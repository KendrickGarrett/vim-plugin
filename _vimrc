"Check environment variables
if ($DEVENV == "")
	echo system("echo DEVENV not set")
	exit
endif

set number
set tabstop=4
set shiftwidth=4
set nowrap
set cursorline
syntax on

set backspace=eol,indent 
set completeopt=menuone,longest,noinsert,noselect
set runtimepath+=$VIMRUNTIME/plugin/mpc/plugin

let mapleader = "-"

nnoremap <leader>so :so %<CR>

syntax keyword winapi printf
syntax keyword winapi malloc
syntax keyword winapi GetLastError
syntax keyword winapi SecureZeroMemory
syntax keyword winapi main WinMain
syntax keyword winapi LookupAccountName LookupAccountNameA LookupAccountNameW
syntax keyword winapi ConvertSidToStringSid ConvertSidToStringSidA ConvertSidToStringSidW
syntax keyword winapi GetSystemRegistryQuota RegCloseKey
syntax keyword winapi FindFirstFile FindFirstFileA FindFirstFileW
highlight link winapi Function

let g:FALSE=0
let g:TRUE=1

let g:projects_dir = $DEVENV."\\proj\\"
let g:dummy = "Dummy".g:projects_dir

nnoremap <leader>cp :call CreateProjectCommand()<CR>
"nnoremap <leader>dp
"nnoremap <leader>lp

function! CreateProjectCommand()
	let l:projname = input("Enter a name for the new project: ")
	call execute ("normal! :")
	call CreateProject(l:projname)
endfunction

function! CreateProject(projname)
	let l:projdir = g:projects_dir.a:projname

	if (isdirectory(l:projdir))
		echo "Project already exists"
		return
	endif
	echo "\n"

	let l:project_config = [
		\a:projname." config file\r\n", 
		\"Enter configuration here\r\n"
	\]

	call mkdir(l:projdir)
	call mkdir(l:projdir."\\inc")
	call mkdir(l:projdir."\\rsc")
	call mkdir(l:projdir."\\src")
	call mkdir(l:projdir."\\obj")
	call writefile(l:project_config, l:projdir."\\".a:projname.".cnf") 
	call writefile(["/*", "*/"], l:projdir."\\src\\".a:projname.".c")

	call RegSetValue("HKCU", "Environment", "CurrentProject", "REG_SZ", a:projname)
	let g:current_project = l:projdir
endfunction

function! DestroyProject()
	if(exists("g:current_project"))
		echo "The current project is".g:current_project
	endif
endfunction

"Load a project from the projects config file into the current buffer
nnoremap <leader>lp :call LoadProjectCommand()<CR>
function! LoadProjectCommand()
	let l:projname = input("Enter the name of the project to load: ")
	echo "\n"
	call LoadProject(l:projname)
endfunction

function! LoadProject(projname)
	let l:projdir = g:projects_dir.a:projname
	if (!isdirectory(l:projdir))
		echo "Error: Project does not exists"
		return
	endif

	call RegSetValue("HKCU", "Environment", "CurrentProject", "REG_SZ", a:projname)
	let g:current_project = l:projdir

	"projects\projectname\projectname.cnf
	let l:file = l:projdir."\\".a:projname.".cnf"
	if(!filereadable(l:file))
		echo "There was an issue with the project config file"
		return 
	endif

	let l:lines = readfile(l:file)
	for l:line in l:lines
		if((l:line[0] == "#"))
			continue
		endif

		if(l:line[0:3] == "main")
			let l:option = split(l:line, "=")	

			execute "normal! bd <C-a>>"
			execute "silent :e ". l:projdir."\\".l:option[1]
			execute "redraw!"
			execute "cd ".l:projdir

		endif
	endfor
endfunction

function! DeleteAllBuffers()
	let i = 1
	
	while bufexists(i) > 0
		execute ":bd ".i
		let i = i+1
	endwhile
endfunction

nnoremap <leader>bp :call BuildProjectCommand()<CR>

function! Build()
	let l:cmd = "cl "
	echo system(l:cmd)
endfunction

"**************************************
"Registry Functions
"**************************************

function! RegAddKey(regroot, regkey)
	let l:cmd = "REG ADD \"".a:regroot."\\".a:regkey."\""
	"echo l:cmd
	echo system(l:cmd)
endfunction

function! RegSetValue(regroot, regkey, valuename, datatype, data)
	let l:cmd = "REG ADD \"".a:regroot."\\".a:regkey."\" /v \"".a:valuename."\" /t ".a:datatype." /d \"".a:data."\" /f"
	call system(l:cmd)
endfunction

function! RegKeyExists(regroot, regkey)
	let l:cmd = "REG QUERY \"".a:regroot."\\".a:regkey."\""

	if (Strip(system(l:cmd))[0:4] == "ERROR")
		return g:FALSE
	else
		return g:TRUE
	endif
endfunction

function! RegValueExists(regroot, regkey, valuename)
	let l:cmd = "REG QUERY \"".a:regroot."\\".a:regkey."\" /v \"".a:valuename."\""

	let l:str = Strip(system(l:cmd))
	if(l:str[0:4] == "ERROR")
		return g:FALSE
	else
		return g:TRUE
	endif
endfunction

function! RegGetData(regroot, regkey, valuename)
	let l:cmd = "REG QUERY \"".a:regroot."\\".a:regkey."\" /v \"".a:valuename."\""
	let l:str = system(l:cmd)
	if (Strip(l:str)[0:4] == 'ERROR')
		return 
	endif
	return split(l:str)[3]
endfunction

function! BoolToString(bool)
	if(a:bool)
		return "TRUE"
	else
		return "FALSE"	
	endif
endfunction

"Trim all white space from the beginning and end of a string
function! Strip(string)
	let l:nstr = substitute(a:string, '^[\r\n\s]*\(.\{-}\)[\r\n\s]*$', '\1', '')
	return l:nstr
endfunction

let g:current_project_name = RegGetData("HKCU", "Environment", "CurrentProject")
let g:current_project = g:projects_dir.g:current_project_name

nnoremap <leader>ep :Ex 
