let SessionLoad = 1
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
cd ~/ft_printf
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +0 ft_printf.h
badd +0 print_float.c
badd +0 ft_printf.c
badd +3 ft_print_type.c
badd +3 Makefile
badd +0 float_utils.c
argglobal
silent! argdel *
$argadd ft_printf.h
edit ft_printf.c
set splitbelow splitright
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
3wincmd h
wincmd w
wincmd w
wincmd w
set nosplitbelow
set nosplitright
wincmd t
set winminheight=1 winminwidth=1 winheight=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 67 + 136) / 272)
exe 'vert 2resize ' . ((&columns * 68 + 136) / 272)
exe 'vert 3resize ' . ((&columns * 67 + 136) / 272)
exe 'vert 4resize ' . ((&columns * 67 + 136) / 272)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 476 - ((55 * winheight(0) + 34) / 68)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
476
normal! 05|
wincmd w
argglobal
if bufexists('float_utils.c') | buffer float_utils.c | else | edit float_utils.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 40 - ((39 * winheight(0) + 34) / 68)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
40
normal! 018|
wincmd w
argglobal
if bufexists('print_float.c') | buffer print_float.c | else | edit print_float.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 60 - ((47 * winheight(0) + 34) / 68)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
60
normal! 011|
wincmd w
argglobal
if bufexists('ft_printf.h') | buffer ft_printf.h | else | edit ft_printf.h | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 100 - ((47 * winheight(0) + 34) / 68)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
100
normal! 055|
wincmd w
2wincmd w
exe 'vert 1resize ' . ((&columns * 67 + 136) / 272)
exe 'vert 2resize ' . ((&columns * 68 + 136) / 272)
exe 'vert 3resize ' . ((&columns * 67 + 136) / 272)
exe 'vert 4resize ' . ((&columns * 67 + 136) / 272)
tabnext 1
if exists('s:wipebuf') && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 winminheight=1 winminwidth=1 shortmess=filnxtToOFc
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :