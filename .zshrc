bindkey -v # Vim modeを有効化

# 日本語環境設定
export LANG=ja_JP.UTF-8
export LC_ALL=ja_JP.UTF-8

# 日本語入力設定
export GTK_IM_MODULE=fcitx
export QT_IM_MODULE=fcitx
export XMODIFIERS=@im=fcitx
source /usr/share/zsh-autosuggestions/zsh-autosuggestions.zsh
source /usr/share/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh

# デフォルトのテキストエディタの設定
export EDITOR=vim

# ディレクトリ移動履歴（cdr）の設定
autoload -Uz chpwd_recent_dirs cdr add-zsh-hook
add-zsh-hook chpwd chpwd_recent_dirs
zstyle ':chpwd:*' recent-dirs-max 20
zstyle ':chpwd:*' recent-dirs-default true

# パスの表示設定（色付き）
autoload -Uz colors && colors
PROMPT="%F{cyan}%n@%m%f:%F{yellow}[%~]%f$ "

# .zsh_historyの設定
export HISTFILE=~/.zsh_history
export HISTSIZE=10000
export SAVEHIST=10000
setopt inc_append_history
setopt share_history
setopt hist_ignore_dups
setopt hist_ignore_space
