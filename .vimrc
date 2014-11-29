
set incsearch
set autoindent
set number
set showmatch
set showmode
colorscheme fu
syntax on
"cp='".,;)]}
"set bg=light
set ignorecase
set smartcase
set scrolloff=3
filetype on
filetype plugin on
filetype indent on
set hlsearch
set smarttab


fu! Pythonbla()
	:wa
	:!sh debug.sh
	"exec "sh debug.sh"
endfunction

map <Leader>p :call Pythonbla()<CR>

map <C-h>  <C-W>h
map <C-j>  <C-W>j
map <C-k>  <C-W>k
map <C-l>  <C-W>l

map <F5> :tabnew<cr>
map <F6> :tabclose<cr>
map <F7> :tabp<cr>
map <F8> :tabn<cr>
