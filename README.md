# Check Qt 简介
**该项目旨在备份MinGW编译器在C++语言下基于Qt开发软件的框架，任何满足条件的软件都可以直接套用该模板进行开发。**
当前版本：**V2.0**。已经实现了下列功能：
+ 头文件、源文件等模块化，且分别位于 `include` 和 `src` 目录。
+ 可读取资源文件，放置在 `resource` 中。
+ 配置完成了CMake选项，并生成了Release版软件目录，见 `build/Release`。
+ 包含了专用于Qt的 `.vscode` 配置文件。
---

# 基于C++和CMake及Qt框架的GUI软件开发基础配置

## 环境配置
#### 1. 安装Visual Studio Code
Visual Studio Code是一款代码编辑器，由于其自由度高、插件丰富，因此很多开发者会选择使用这款编辑器。但是Visual Studio Code不含编译器，需要自行配置。

#### 2. 安装编译器
一般而言，在Windows系统上，编译器可以直接使用MSVC，即微软公司的C++开发工具。但为了多端兼容性，有时也会选择安装MinGW，因为这种编译器可以同时支持Windows、MacOS、Linux系统。

#### 3. 安装Qt及其组件
在这一步，不仅会安装Qt的基本组件和Qt Creator，而且还要选择安装与Qt配套的编译器（MSVC、MinGW等），不可以因为本地有编译器就不安装了，否则会引起编译错误！在这个过程中，CMake也会被安装。

#### 4. 配置插件
必须安装的插件有：
```Text
C/C++
C/C++ Extension Pack
CMake IntelliSence
CMake Tools
Code Runner
```
推荐安装的插件有：
```Text
C/C++ Themes
Chinese (simplified)
Material Icon Theme
...
```

## 注意事项
#### 1. 关于编译器
在一般的编译环境中使用的解释器，与在Qt安装包的Tools内的解释器是不一样的。在其他情况下，编译器直接使用自行安装的即可；但在使用Qt时，必须使用其配套的编译器！

#### 2. 环境变量需手动加入
环境变量要手动设置，需要把MinGW（或MSVC）、Qt、CMake的主文件夹和bin文件夹均加入到系统环境变量中，否则在编译或生成时可能搜不到。

#### 3. 创建Qt工程的顺序
一般创建一个基于Qt开发的GUI工程时，要先用Qt Creator创建一个新项目，然后使用默认的CMake内容生成。确认无误后，在Visual Studio Code中打开这个项目，在配置文件夹.vscode中加入文件 `c_cpp_properties.json` ，其内写入下列内容，让CMake自动管理所有Qt库：
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
其中 `name` 可以自定义，一般建议与你的配套编译器一致，便于区分。
此外，还可以加入 `settings.json` 文件，内容如下：
```JSON
{
    "files.associations": {
        "qapplication": "cpp"
    }
}
```
此时，在安装有CMake Tools插件的前提下，生成CMake，此时会出现一个build文件夹，再运行程序即可跑通。

#### 4. 模块化
若工程是模块化的，即源文件放置于 `src` 文件夹内，头文件放置在 `include` 文件夹内，动态库在 `bin` 内，静态库在 `lib` 内，诸如此类.在 `CMakeLists.txt` 中，要手动修改源文件、头文件、链接库等，比如：
```CMake
# 设置头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include)
# 添加源文件
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_FILES)
# 添加可执行文件
add_executable(checkQt ${SRC_FILES})
# 链接 Qt 库
target_link_libraries(checkQt PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets)
```
如无需配置Android和MacOS系统的UI，则可以删去 `CMakeLists.txt` 中相关部分代码。

## 生成 Release 版软件
当前已经更新了 `CMakeLists.txt` 使其能在 `build` 下生成 `Release` 的独立软件，可以直接将代码迁移至其他工程中，稍作修改后即可使用。
