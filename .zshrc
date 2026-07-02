# ==============================================================================
# 1. 基本設定 (既存設定の維持と最適化)
# ==============================================================================
bindkey -v # Vim modeを有効化

# 日本語環境設定
export LANG=ja_JP.UTF-8
export LC_ALL=ja_JP.UTF-8

# 日本語入力設定
export GTK_IM_MODULE=fcitx
export QT_IM_MODULE=fcitx
export XMODIFIERS=@im=fcitx

# プラグインの読み込み (存在確認を行って安全にロード)
[[ -f /usr/share/zsh-autosuggestions/zsh-autosuggestions.zsh ]] && source /usr/share/zsh-autosuggestions/zsh-autosuggestions.zsh
[[ -f /usr/share/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh ]] && source /usr/share/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh

# デフォルトのテキストエディタの設定
export EDITOR=vim

# ディレクトリ移動履歴（cdr）の設定
autoload -Uz chpwd_recent_dirs cdr add-zsh-hook
add-zsh-hook chpwd chpwd_recent_dirs
zstyle ':chpwd:*' recent-dirs-max 20
zstyle ':chpwd:*' recent-dirs-default true

# .zsh_historyの基本設定 (履歴の共有や保存のポリシー)
export HISTSIZE=10000
export SAVEHIST=10000
setopt inc_append_history
setopt share_history
setopt hist_ignore_dups
setopt hist_ignore_space

# ==============================================================================
# 2. モード（作業環境）管理システム
# ==============================================================================
# モード情報を永続化するファイル
MODE_SAVE_FILE="$HOME/.zsh_modes"

# 連想配列を利用できるように宣言
typeset -A MODE_DIRS
typeset -A MODE_LABELS

# --- モードの初期化関数 ---
function _init_modes() {
    # デフォルトモードのみ初期設定
    MODE_LABELS[default]="Default"
    MODE_DIRS[default]="$HOME"

    # 保存ファイルが存在する場合は、追加したカスタムモードをロード
    if [[ -f "$MODE_SAVE_FILE" ]]; then
        source "$MODE_SAVE_FILE"
    fi
}

# --- カスタムモードの保存関数 ---
function _save_modes() {
    echo "# Dynamic zsh modes (generated automatically)" > "$MODE_SAVE_FILE"
    for k in ${(k)MODE_DIRS}; do
        # 外部ファイルにはカスタムモードのみを書き出す（defaultは初期化関数で定義するため除外）
        if [[ "$k" != "default" ]]; then
            echo "MODE_LABELS[$k]='${MODE_LABELS[$k]}'" >> "$MODE_SAVE_FILE"
            echo "MODE_DIRS[$k]='${MODE_DIRS[$k]}'" >> "$MODE_SAVE_FILE"
        fi
    done
}

# 初期読み込みを実行
_init_modes

# --- モード切り替え・作成関数 ---
function change_mode() {
    local target_mode=$1

    # --- モードの新規作成 (mode create <名前> [ディレクトリパス]) ---
    if [[ "$target_mode" == "create" ]]; then
        local new_mode=$2
        local new_dir=$3

        if [[ -z "$new_mode" ]]; then
            echo "エラー: モード名を指定してください。"
            echo "使用方法: mode create <モード名> [作業ディレクトリ]"
            return 1
        fi

        # ディレクトリが省略された場合は、現在のディレクトリ（PWD）を使用
        if [[ -z "$new_dir" ]]; then
            new_dir="$PWD"
        else
            # プレースホルダ（$HOMEなど）を展開し、絶対パスを取得
            new_dir=$(eval echo "$new_dir")
            new_dir=$(cd "$new_dir" 2>/dev/null && pwd || echo "$new_dir")
        fi

        # ディレクトリの存在チェック（新規作成はしません）
        if [[ ! -d "$new_dir" ]]; then
            echo "エラー: ディレクトリ '$new_dir' が存在しません。"
            echo "すでに存在する作業用のディレクトリを指定、またはその場所に移動してから作成してください。"
            return 1
        fi

        # メモリ上の連想配列に追加し、外部ファイルへ保存
        MODE_LABELS[$new_mode]="$new_mode"
        MODE_DIRS[$new_mode]="$new_dir"
        _save_modes

        echo "モード '$new_mode' を登録しました。[作業ディレクトリ: $new_dir]"
        return 0
    fi

    # --- 通常のモード切り替え・一覧表示 ---
    # 引数がない、または定義されていないモードが指定された場合はリストを表示
    if [[ -z "$target_mode" || -z "${MODE_DIRS[$target_mode]}" ]]; then
        echo "Usage"
        echo "  mode <mode name : change mode"
        echo "  mode create <mode name> [path] : create new mode in dirctly"
        echo ""
        echo "changable mode"
        for k in ${(k)MODE_DIRS}; do
            local current_marker=" "
            if [[ "$k" == "$CURRENT_MODE" ]]; then
                current_marker="*"
            fi
            printf " %s %-10s -> %s (%s)\n" "$current_marker" "$k" "${MODE_DIRS[$k]}" "${MODE_LABELS[$k]}"
        done
        return 1
    fi

    # 1. 履歴を現在のファイルに書き出して一度クリア
    fc -W
    fc -p

    # 2. 現在のモード変数を更新
    export CURRENT_MODE="$target_mode"

    # 3. モード個別の履歴ファイルパスを設定
    if [[ "$CURRENT_MODE" == "default" ]]; then
        export HISTFILE=~/.zsh_history
    else
        # モードごとの履歴ファイルを分ける
        export HISTFILE=~/.zsh_history_${CURRENT_MODE}
    fi

    # 4. 新しい履歴ファイルを読み込み
    fc -R "$HISTFILE"

    # 5. 指定された作業ディレクトリに移動 (新規作成は行わない)
    local target_dir="${MODE_DIRS[$CURRENT_MODE]}"
    target_dir=$(eval echo "$target_dir")

    if [[ -d "$target_dir" ]]; then
        cd "$target_dir"
    else
        echo "警告: ディレクトリ '$target_dir' が存在しないため、移動をスキップしました。"
    fi

    # プロンプトを再描画
    zle && zle reset-prompt
}

# エイリアス（コマンドとして実行できるように登録）
alias mode=change_mode

# 起動時の初期モード設定
export CURRENT_MODE="default"
export HISTFILE=~/.zsh_history

# ==============================================================================
# 3. パス・プロンプトの表示設定（色付き ＆ モード連動）
# ==============================================================================
autoload -Uz colors && colors

# プロンプトの構築関数
function set_custom_prompt() {
    # モードに応じたラベルの色分け
    local mode_color="cyan"
    if [[ "$CURRENT_MODE" != "default" ]]; then
        mode_color="green" # 追加されたカスタムモードは緑色で表示
    fi

    local label="${MODE_LABELS[$CURRENT_MODE]:-$CURRENT_MODE}"
    local mode_display="%F{$mode_color}[${label}]%f "
    
    # プロンプト全体の組み立て
    PROMPT="${mode_display}%F{cyan}%n@%m%f:%F{yellow}[%~]%f$ "
}

# プロンプトを動的に更新するためのhook
add-zsh-hook precmd set_custom_prompt
