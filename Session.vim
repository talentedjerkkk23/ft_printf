let SessionLoad = 1
if &cp | set nocp | endif
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/ft_printf
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +1 ft_printf.h
badd +1 print_float.c
badd +19 ft_printf.c
badd +31 ft_print_type.c
badd +1 Makefile
badd +27 float_utils.c
badd +1 print_octal.c
badd +1 main.c
badd +9 print_char.c
badd +88 print_unsigned_decimal.c
badd +0 print_string.c
argglobal
silent! argdel *
$argadd ft_printf.h
tabnew
tabnext -1
edit print_string.c
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
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 79 + 159) / 318)
exe 'vert 2resize ' . ((&columns * 79 + 159) / 318)
exe 'vert 3resize ' . ((&columns * 79 + 159) / 318)
exe 'vert 4resize ' . ((&columns * 78 + 159) / 318)
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
let s:l = 41 - ((40 * winheight(0) + 38) / 76)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
41
normal! 0
wincmd w
argglobal
if bufexists('print_octal.c') | buffer print_octal.c | else | edit print_octal.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 98 - ((65 * winheight(0) + 38) / 76)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
98
normal! 010|
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
let s:l = 35 - ((28 * winheight(0) + 38) / 76)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
35
normal! 05|
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
let s:l = 84 - ((37 * winheight(0) + 38) / 76)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
84
normal! 05|
wincmd w
exe 'vert 1resize ' . ((&columns * 79 + 159) / 318)
exe 'vert 2resize ' . ((&columns * 79 + 159) / 318)
exe 'vert 3resize ' . ((&columns * 79 + 159) / 318)
exe 'vert 4resize ' . ((&columns * 78 + 159) / 318)
tabnext
edit main.c
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
set nosplitbelow
set nosplitright
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 159 + 159) / 318)
exe 'vert 2resize ' . ((&columns * 158 + 159) / 318)
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
let s:l = 834 - ((45 * winheight(0) + 38) / 76)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
834
normal! 0
wincmd w
argglobal
if bufexists('Makefile') | buffer Makefile | else | edit Makefile | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 41 - ((40 * winheight(0) + 38) / 76)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
41
normal! 06|
wincmd w
exe 'vert 1resize ' . ((&columns * 159 + 159) / 318)
exe 'vert 2resize ' . ((&columns * 158 + 159) / 318)
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToOFc
set winminheight=1 winminwidth=1
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
