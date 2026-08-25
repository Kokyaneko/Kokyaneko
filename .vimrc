set number          " 行番号を表示する
set cursorline      " 現在の行をハイライトする
set laststatus=2    " ステータスラインを常に表示する
syntax on           " コードのシンタックスハイライトを有効にする

set tabstop=4       " 画面上でタブ文字が占める幅
set shiftwidth=4    " 自動インデント時のズレ幅
set expandtab       " タブ入力を複数のスペースに変換する
set autoindent      " 改行時に前の行のインデントを継続する

set wildmenu
set showcmd

" タグファイルの指定
set tags=tags;


" セッションの保存と自動復元
set sessionoptions=blank,buffers,curdir,folds,help,tabpages,winsize

function! s:make_session_clean()
    let l:buflist = range(1, bufnr('$'))
    for l:buf in l:buflist
        if bufexists(l:buf) && buflisted(l:buf)
            call setbufvar(l:buf, '&filetype', '')
        endif
    endfor
    mksession! ~/.vim_current_session.vim
endfunction

autocmd VimLeave * call s:make_session_clean()

function! s:load_session_safe()
    if argc() == 0 && filereadable(expand('~/.vim_current_session.vim'))
        source ~/.vim_current_session.vim
        bufdo filetype detect
        syntax on
    endif
endfunction

autocmd VimEnter * call s:load_session_safe()
