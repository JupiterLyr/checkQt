# Brief Introduction to Check Qt
**该项目旨在备份 MinGW 编译器在 C++ 语言下基于 Qt 开发软件的框架，任何满足条件的软件都可以直接套用该模板进行开发。**</br>
**This project aims to back up the framework of MinGW compiler developing software based on Qt in C++ language, and any software that meets the requirements can be directly developed by applying this template.**</br>

**Note**: </br>
该版本的开发框架需要手动编写 `ui.h` 和 `ui.cpp`，如要兼容利用 Qt Creator 的 `*.ui` 文件，请移步：</br>
This version of the development framework needs to manually write `ui.h` and `ui.cpp`. To be compatible with the `*.ui` file of Qt Creator, please visit:</br>
[Check Qt -- with UI Configuration](https://github.com/JupiterLyr/checkQt--withUIconfig)

---

Current Version: **V3.0**. The following functions have been realized:
- 头文件、源文件等模块化，且分别位于 `include` 和 `src` 目录。
- 可读取资源文件，放置在 `resource` 中。
- 配置完成了 CMake 选项，并生成了 Release 版软件目录，见 `build/Release`。
- 包含了专用于 Qt 的 `.vscode` 配置文件，但 JSON 具体配置需根据特定计算机进行调整。
- 加入了 `icon_config.rc`，配置了图标文件。
- 增设了安装包配置文件（详见 `installer/config/` 和 `installer/packages`），并用批处理文件 `create_installer.bat` 创建安装包。
- 当前版本的 `CmakeLists.txt` 可以在简单修改后兼容 `*.ui` 文件的配置。

- The header files and source files are modularized and located in the `include` and `src` directories respectively.
- The resource file to be read is placed in `resource`.
- The CMake option is configured, and the Release software directory is generated, which is located in `build/Release`.
- The `.vscode` configuration file dedicated to Qt is already included. However, the JSON configuration needs to be adjusted according to the situation of a specific computer.
- The `icon_config.rc` is added and the icon file is configured.
- The installation package configuration file is completed (see `installer/config/` and `installer/packages/` for details). The installation package is created with the batch file `create_installer.bat`.
- The current version of `CmakeLists.txt` can be compatible with the configuration of `*.ui` file after simple modification.

---

# 基于C++和CMake及Qt框架的GUI软件开发基础配置</br>Basic Configuration of GUI Software Dev. Based on C++, CMake & Qt Framework

## 环境配置</br>Environmental Configuration
### 1. 安装 Visual Studio Code (Install VS Code)
Visual Studio Code 是一款代码编辑器，由于其自由度高、插件丰富，因此很多开发者会选择使用这款编辑器。但是 Visual Studio Code 不含编译器，需要自行配置。</br>
Visual Studio Code is a code editor. Many developers will choose to use this editor because of its high freedom and rich plug-ins. But it does not include a compiler and needs to be configured by itself.

### 2. 安装编译器 (Install The Compiler)
一般而言，在 Windows 系统上，编译器可以直接使用 **MSVC**，即微软公司的 C++ 开发工具。但为了多端兼容性，有时也会选择安装 **MinGW**，因为这种编译器可以同时支持 Windows、MacOS、Linux 系统。</br>
Generally speaking, on the Windows system, the compiler can directly use **MSVC**, i.e., the C++ development tool of Microsoft. However, for multi-port compatibility, **MinGW** is sometimes installed, for this compiler can support Windows, MacOS and Linux systems at the same time.

### 3. 安装 Qt 及其组件 (Install Qt And Its Components)
此处不仅会安装 Qt 的基本组件，还要选择安装与 Qt 配套的编译器（如 MinGW 等）。建议为 Qt 选择独立编译器，便于项目管理，避免引起编译错误。在这个过程中，CMake也会被安装。</br>
In this step, not only the basic components of Qt and Qt Creator will be installed, but also compilers matching it (e.g., MinGW, etc.) will be installed. It is suggested to choose an independent compiler for Qt to facilitate project management and avoid compilation errors. During this process, CMake will also be installed.

### 4. 配置插件 (Plug-in Configuration)
必须安装的插件有：</br>The plug-ins that must be installed are:
```Text
C/C++
C/C++ Extension Pack
CMake IntelliSence
CMake Tools
Code Runner
```
推荐安装的插件有：</br>Recommended plug-ins are:
```Text
C/C++ Themes
Chinese (simplified)
Material Icon Theme
...
```
The use of plug-ins can be dynamically adjusted according to personal preferences and project requirements.

## 注意事项</br>Attention
### 1. 关于编译器 (About Compiler)
在一般的编译环境中使用的解释器，与 Qt 的 Tools 内的解释器是不一样的。推荐您在其他情况下直接使用外部编译器，而在使用 Qt 时采用配套的编译器！</br>
The interpreter used in the general compilation environment is different from the interpreter in Qt Tools. It is recommended that you use an external compiler directly in other cases, and use a matching compiler when using Qt!

### 2. 手动加入环境变量 (Manually Add Environment Variables)
环境变量要手动设置，需要把 MinGW（或其他编译器）、Qt、CMake 的主文件夹和 bin 文件夹均加入到系统环境变量中，否则在编译或生成时可能搜不到。</br>
Environment variables should be set manually. You need to add MinGW (or other compilers), Qt, CMake's home folder and bin folder to the system environment variable. Otherwise, it may not be found during compilation or generation.

### 3. 创建 Qt 工程的顺序 (Order of Creating Qt Project)
一般创建一个基于 Qt 开发的 GUI 工程时，要先用 Qt Creator 创建一个新项目，然后使用默认的 CMake 内容生成。在确认无误后，在 Visual Studio Code 中打开这个项目，在配置文件夹 .vscode 中加入文件 `c_cpp_properties.json` ，其内写入下列内容，让 CMake 自动管理所有 Qt 库：</br>
Generally, when creating a GUI project based on Qt development, you should first create a new project with Qt Creator and generate it with the default CMake content. After confirmation, open this project in Visual Studio Code and add the file `c _ CPP _ properties.json` to the configuration folder. vscode. Write the following contents in it, and let CMake automatically manage all Qt libraries:
```JSON
{
    "configurations": [
        {
            "name": "gcc_13-1-0_cmake",
            // Give Qt related header files to CMake for automatic management
            "configurationProvider": "ms-vscode.cmake-tools",
            "mergeConfigurations": true
        }
    ],
    "version": 4
}
```
其中 `name` 可以自定义，一般建议与你的配套编译器一致，便于区分。</br>
此外，还可以加入 `settings.json` 文件，内容如下：</br>
Among them, `name` can be customized, and it is generally recommended to be consistent with your supporting compiler for easy distinction.</br>
In addition, you can also add a `settings.json` file, which reads as follows:
```JSON
{
    "files.associations": {
        "qapplication": "cpp"
    }
}
```
此时，在安装有 CMake Tools 插件的前提下，生成 CMake，此时会出现一个 build 文件夹，再运行程序即可跑通。</br>
At this point, under the premise of installing the CMake Tools plug-in, generate CMake, and a build folder will appear at this time, and then run the program to get through.

### 4. 模块化 (Modularize)
若工程是模块化的，即源文件放置于 `src` 文件夹内，头文件放置在 `include` 文件夹内，动态库在 `bin` 内，静态库在 `lib` 内，诸如此类。在 `CMakeLists.txt` 中，要手动修改源文件、头文件、链接库等，比如：</br>
If the project is modular, i.e., the source files are placed in the `src` folder, the header files are placed in the `include` folder, the dynamic library is in the `bin`, the static library is in the `lib`, and so on. In the `CMakeLists.txt`, the source files, header files, link libraries, etc. should be modified manually, e.g.:
```CMake
# Set header file directory
include_directories(${PROJECT_SOURCE_DIR}/include)
# Add source file
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_FILES)
# Add an executable file
add_executable(checkQt ${SRC_FILES})
# Link to Qt library
target_link_libraries(checkQt PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets)
```
如无需兼容配置 Android 等系统，则可以删去 `CMakeLists.txt` 中相关部分代码。</br>
If you don't need to configure Android and other systems compatibly, you can delete some codes in `CMakeLists.txt`.

## 生成 Release 版软件</br>Generate Release Software
当前已经更新了 `CMakeLists.txt` 使其能在 `build` 下生成 `Release` 的独立软件，可以直接将代码迁移至其他工程中，稍作修改后即可使用。</br>
At present, `CMakeLists.txt` has been updated to enable it to generate `Release` independent software under `build`. You can directly migrate the code to other projects, and you can use it after a little modification.

## 生成软件安装包</br>Generate Installation Package
在路径 `installer` 下，`config` 存放安装包配置文件，`packages` 下为包名，命名格式为“com.公司名.应用名”，其内的 `data` 与 `build/Release` 一致，`meta` 为包设置。使用根目录下的 `create_installer.bat` 生成安装包。</br>
Under the path `installer`, `config` stores the installation package configuration file. The folders under `packages` is the name of the packages, whose naming format is "com.company_name.app_name". The `data` in it is consistent with `build/Release`, and `meta` is the package setting. Run `create_installer.bat` in the root directory to generate the installation package.
