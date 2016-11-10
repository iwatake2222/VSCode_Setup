# Visual Studio Code setup

## Target environment
* Windows 10
* MinGW for CPP

## Minor settings
* Change language
    * Ctrl+Shift+P -> Configure Language
        * "locale":"en-US"
* User settings
    * File -> Preferences -> User settings -> settings.json
```
    // Word Wrap
    "editor.wrappingColumn": 0,
    // Display white space
    "editor.renderWhitespace": true,
    "python.pythonPath": "c:/Users/tak/AppData/Local/Programs/Python/Python35-32/python.exe",
    "workbench.statusBar.visible": true
```

## Python
### Install
* Install Python 2 or 3
	* using the original package
* Install lint
	* pip install lint
* Add Python extension(donjayamanne.python) into VSCode

### Setup python path (need this operation only once)
* File -> Preferences -> User settings -> settings.json
    * "python.pythonPath": "c:/Users/myname/AppData/Local/Programs/Python/Python35-32/python.exe",

### Setup task runner (need this operation for each workspace)
* Open a folder including your python scripts
* Ctrl+Shift+b to try to run the scripts, and click Configure Task Runner
	* select "Others"
* modify tasks.json like the following
```
{
    "version": "0.1.0",
    "command": "python",
    "isShellCommand": true,
    "args": ["${file}"],
    "showOutput": "always",
    "problemMatcher": "$tsc"
}
```

* Press Ctrl+Shift+b on the target python script, then script will run

### Debug
* Click the debug button, and start debugging(F5)
* Select Python. You don't need to modify launch.json which was automatically generated
* Press F5 again, then debugging will start

## C/CPP
### Install
* Install MinGW
* Add C/C++ extension(ms-vscode.cpptools) into VSCode

### Add include path
* Click on any include statement with underline
* click the lamp icon and "Add include path to settings"
* Modify "c_cpp_properties.json"
```
            "name": "Win32",
            "includePath": ["c:/MinGW/include"],
```

### Setup task runner (need this operation for each workspace)
* Open a folder including your C/CPP files
* Ctrl+Shift+b to try to build the source codes, and click Configure Task Runner
	* select "Others"
* Modify tasks.json like the following (but it looks working only for single source code...)
```
{
    "version": "0.1.0",
    "command": "g++",
    "isShellCommand": true,
    "args": ["-g", "${file}"],
    "showOutput": "always",
    "problemMatcher": "$tsc"
}
```

* If you want to use your own makefile and you want to compile multiple source codes, modify tasks.json like the following
    * Default Ctrl+Shift+b will run make all
    * Ctrl+p -> task (space) will show compile options
```
{
    "version": "0.1.0",
    "command": "mingw32-make",
    "isShellCommand": true,
    "showOutput": "always",
    "tasks": [
    {
        "taskName": "all",
        "args": ["all"],
        "problemMatcher": "$tsc",
        "isBuildCommand": true
    },
    {
        "taskName": "clean",
        "args": ["clean"],
        "problemMatcher": "$tsc"
    },
    {
        "taskName": "cleanall",
        "args": ["clean", "all"],
        "problemMatcher": "$tsc"
    }
    ]
}
```

* Press Ctrl+Shift+b on the target main source code, and a.exe will be generated 
* Note: makefile syntax of mingw-make looks different from that of linux

### Debug
* Click the debug button, and start debugging(F5)
* Select C++(GDB/LLDB)
* Modify launch.json to change program fields and add miDebuggerPath field
```
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "C++ Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceRoot}/a.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceRoot}",
            "environment": [],
            "externalConsole": true,
            "linux": {
                "MIMode": "gdb"
            },
            "osx": {
                "MIMode": "lldb"
            },
            "windows": {
                "MIMode": "gdb"
            },
            "miDebuggerPath": "c:/mingw/bin/gdb.exe"
        },
        {
            "name": "C++ Attach",
            "type": "cppdbg",
            "request": "attach",
            "program": "${workspaceRoot}/a.exe",
            "processId": "${command.pickProcess}",
            "linux": {
                "MIMode": "gdb"
            },
            "osx": {
                "MIMode": "lldb"
            },
            "windows": {
                "MIMode": "gdb"
            }
        }
    ]
}
```
* Press F5 again, then debug will start

