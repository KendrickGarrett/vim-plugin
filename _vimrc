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

syntax keyword winapi printf
syntax keyword winapi malloc
syntax keyword winapi GetLastError
syntax keyword winapi SecureZeroMemory
syntax keyword winapi main WinMain
syntax keyword winapi LookupAccountName LookupAccountNameA LookupAccountNameW
syntax keyword winapi ConvertSidToStringSid ConvertSidToStringSidA ConvertSidToStringSidW
syntax keyword winapi GetSystemRegistryQuota RegCloseKey
"syntax keyword winapi FindFirstFile FindFirstFileA FindFirstFileW
syntax keyword winapi FindFirstFile[A]
highlight link winapi Function

let g:FALSE=0
let g:TRUE=1

function! CreateProject()
	let l:projname = input("Enter for the new project: ") 
	call execute "normal! :"

	if (isdirectory($DEVENV."\\proj\\".projname))
		echo "Project already exists"
		return
	endif

	let g:current_project = $DEVENV."\\proj\\".projname

	echo "\n"
	let new_project = $DEVENV."\\projects\\".projname
	let project_config = [projname." config file", "Enter configuration here"]
	call system("mkdir ".new_project)
	call writefile(["Hello"], new_project."\\".projname.".cnf") 
endfunction

function! DestroyProject()
	if(exists("g:current_project"))
		echo "The current project is".g:current_project
	endif
endfunction

"Load a project from the projects config file into the current buffer
function! LoadProject()
	let l:projname = input("Enter the name of the project to load: ")
	echo "\n"
	let l:projdir = $DEVENV."\\proj\\".l:projname
	if (!isdirectory(l:projdir))
		echo "Error: Project does not exists"
		return
	endif

	call RegSetValue("HKCU", "Environment", "CurrentProject", "REG_SZ", l:projname)

	"projects\projectname\projectname.cnf
	let l:file = l:projdir."\\".l:projname.".cnf"
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

function! Build()
	echo "Building the project"
	call system("cl ")
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
