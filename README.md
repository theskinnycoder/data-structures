# **SETUP FOR THE TUTORIAL :**

## **1) INSTALL THE TOOLS :**

### **a) Windows (_eww_) :**

1. Download [Mingw-w64](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download).
2. Make sure you add its **`bin/`** folder to the **PATH**.

### **b) Linux (_the Gods_) :**

Install the compiler and the deBugger :

```bash
# For example, on Debain-based systems :
sudo apt install build-essential gdb
```

### **c) Mac (_lucky you_) :**

Install the compiler and the deBugger :

```zsh
xcode-select --install
```

---

## **2) INSTALL VSCODE :**

### **a) Windows :**

1.  Visit [VSCode](https://code.visualstudio.com).
2.  Download the Windows-64 'Stable' version.
3.  Follow the installation steps by running the downloaded file, and check the **ADD VSCode to PATH** option for sure.

### **b) Linux :**

- Install using [**`snap`**](https://snapcraft.io/code). Choose your distro type in the list to install **`snap`**.

- **`snap`** is a new global package-manager common to all distros.

```bash
# For example, on Debain-based systems :

# To install snap :
sudo apt update
sudo apt install snapd

# To install VSCode :
sudo snap install code --classic
```

### **c) Mac**

1. Visit [VSCode](https://www.code.visualstudio.com).
2. Download the MacOS 'Stable' version.
3. Follow the installation steps by running the downloaded file

---

## **3) SETUP VSCODE :**

### **a) Install the Extensions :**

- Search for the **[C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)**, and **[C++ Intellisense](https://marketplace.visualstudio.com/items?itemName=austin.code-gnu-global)** extensions and install them.
- You get language-support, auto-complete and intellisense features through these extensions.

> ### Create a **`.vscode/`** folder in your project root.

---

### **b) The `c_cpp_properties.json` file :**

1. Create a **`c_cpp_properties.json`** file in **`.vscode/`**
2. Add the following to the file :

```jsonc
{
  "configurations": [
    {
      "name": "Windows",
      "includePath": ["${workspaceFolder}/**"],
      "defines": ["_DEBUG", "UNICODE", "_UNICODE"],
      "compilerPath": "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/gcc.exe",
      "cStandard": "c17",
      "intelliSenseMode": "gcc-x64"
    },
    {
      "name": "Linux",
      "includePath": ["${workspaceFolder}/**"],
      "defines": ["_DEBUG", "UNICODE", "_UNICODE"],
      "compilerPath": "/usr/bin/gcc",
      "cStandard": "c17",
      "intelliSenseMode": "gcc-x64"
    },
    {
      "name": "Mac",
      "includePath": ["${workspaceFolder}/**"],
      "defines": ["_DEBUG", "UNICODE", "_UNICODE"],
      "compilerPath": "/usr/bin/clang",
      "cStandard": "c17",
      "intelliSenseMode": "clang-x64"
    }
  ],
  "version": 4
}
```

---

### **c) The `tasks.json` file :**

1. Create a **`tasks.json`** file in **`.vscode/`**
1. Add the following to the file :

```jsonc
{
  "version": "2.0.0",
  "type": "shell",

  // General console config
  "presentation": {
    "focus": true,
    "panel": "shared",
    "showReuseMessage": false,
    "clear": false,
    "echo": true
  },

  "tasks": [
    // Compile Task
    {
      "type": "shell",
      "label": "Compile",
      "command": "gcc",
      "args": ["-g", "${file}", "-o", "out/${fileBasenameNoExtension}.exe"],
      "options": {
        "cwd": "${workspaceFolder}"
      },
      "group": "build",
      "linux": {
        "command": "/usr/bin/gcc",
        "args": ["-g", "${file}", "-o", "out/${fileBasenameNoExtension}.out"]
      },
      "osx": {
        "command": "clang",
        "args": ["-g", "${file}", "-o", "out/${fileBasenameNoExtension}"]
      }
    },

    // Run Task
    {
      "type": "shell",
      "label": "Run",
      "command": "out/${fileBasenameNoExtension}.exe",
      "promptOnClose": false,
      "dependsOn": ["Compile"],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "linux": {
        "command": "out/${fileBasenameNoExtension}.out"
      },
      "osx": {
        "command": "out/${fileBasenameNoExtension}"
      }
    }
  ]
}
```

---

### **d) The `launch.json` file :**

1. Create a **`launch.json`** file in **`.vscode/`**
2. Add the following to the file :

```jsonc
{
  "configurations": [
    {
      "name": "deBug",
      "type": "cppdbg",
      "request": "launch",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "MIMode": "gdb",
      "setupCommands": [
        {
          "description": "Enable pretty-printing for gdb",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        }
      ],
      "preLaunchTask": "Compile",
      "externalConsole": false,
      "internalConsoleOptions": "openOnSessionStart",
      "program": "${workspaceFolder}/out/${fileBasenameNoExtension}.exe",
      "miDebuggerPath": "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/gdb.exe",
      "linux": {
        "program": "${workspaceFolder}/out/${fileBasenameNoExtension}.out",
        "miDebuggerPath": "/usr/bin/gdb"
      },
      "osx": {
        "program": "${workspaceFolder}/out/${fileBasenameNoExtension}",
        "miDebuggerPath": "/usr/bin/lldb",
        "MIMode": "lldb"
      }
    }
  ]
}
```

> Happy Coding!
