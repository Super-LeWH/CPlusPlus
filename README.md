# CPlusPlus
This is a repository of CPlusPlus.

# 准备打包成一个可下载的文件
### **完整流程示例**

```bash
# 确保代码是最新的
git add .
git commit -m "Prepare release v1.0.0"
git push origin main

# 创建 Tag
git tag -a v1.0.0 -m "Release version 1.0.0"
git push origin v1.0.0

# 发布 Release (通过 GitHub 网页或 gh 命令行)
gh release create v1.0.0 --title "Version 1.0.0" --notes "First stable release"
```

完成后，其他用户可以从 **"Releases"** 页面下载指定版本的代码或附件。

# 如何实现一个自动化构建
为了创建一个自动化构建的GitHub Actions工作流，你需要确保在 `.github/workflows/ci.yml` 文件中定义了正确的步骤。由于你的项目结构看起来是一个C++项目，并且使用CMake来构建，你可以使用GitHub Actions中的CMake和构建步骤来实现自动化构建。

下面是一个示例的 `ci.yml` 文件，适用于你的项目：

```yaml
name: C++ CI Build

on:
  push:
    branches:
      - main  # 触发工作流的分支，可以根据需要修改
  pull_request:
    branches:
      - main  # 触发PR时的工作流分支

jobs:
  build:
    runs-on: ubuntu-latest  # 可以选择适合你的操作系统，如ubuntu-latest, windows-latest等

    steps:
    - name: Checkout repository
      uses: actions/checkout@v3

    - name: Set up CMake
      uses: actions/setup-cmake@v3
      with:
        cmake-version: '3.30.3'  # 使用你的项目中需要的CMake版本，可以根据实际情况调整

    - name: Set up C++ Build Environment
      uses: actions/setup-toolchain@v1
      with:
        toolchain: 'clang'  # 你也可以根据需要改成gcc或其他工具链

    - name: Install dependencies (optional, based on your project)
      run: |
        sudo apt update
        sudo apt install -y build-essential

    - name: Configure CMake project
      run: |
        mkdir -p build
        cd build
        cmake -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles" ../  # 你可以根据需要调整构建类型

    - name: Build the project
      run: |
        cd build
        cmake --build . --config Release  # 指定构建配置，可以根据需要调整

    - name: Run tests (optional)
      run: |
        cd build
        cmake --build . --target test  # 如果你的项目有测试，可以启用此步骤

    - name: Upload build artifacts (optional)
      uses: actions/upload-artifact@v3
      with:
        name: build-artifacts
        path: build  # 将构建目录上传为构建产物（如果需要）
```

### 解释各个部分：

1. **触发条件（on）**：
   - `push`：当推送到 `main` 分支时触发。
   - `pull_request`：当有 PR 请求针对 `main` 分支时触发。

2. **工作流步骤（steps）**：
   - **Checkout repository**：使用 `actions/checkout` 获取你的代码。
   - **Set up CMake**：使用 `actions/setup-cmake` 来安装和设置CMake。版本可以根据你的项目需要进行调整。
   - **Set up C++ Build Environment**：设置C++构建环境，这里示例使用了 `clang`，可以根据你项目的需求选择 `gcc` 或其他工具链。
   - **Install dependencies**：安装项目可能需要的依赖（这步可以根据你的项目需要进行修改）。
   - **Configure CMake project**：创建构建目录，并配置CMake项目。
   - **Build the project**：执行构建命令，生成你的项目。
   - **Run tests**：可选步骤，运行项目的测试。如果你有单元测试，启用此步骤。
   - **Upload build artifacts**：如果需要，你可以将构建生成的文件作为构建产物上传，方便后续使用或查看。

### 注意事项：
- 请确保你的 `CMakeLists.txt` 文件已经配置好所有依赖和目标。
- 根据你实际的操作系统（例如Windows或Linux），可以调整 `runs-on` 的选项。
- 如果你的项目有特定的依赖或者额外的构建步骤（比如构建库或者需要其他软件包），请在 `Install dependencies` 步骤中添加相关命令。

这种方式能实现每次对 `main` 分支的推送或PR时，自动构建并可选运行测试，确保代码质量和构建成功。
