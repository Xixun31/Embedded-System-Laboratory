🚀 EE2405 Embedded System Laboratory本倉庫用於備份 清大電機 EE2405 課程程式碼，並支援在 Ubuntu (實驗室) 與 macOS (個人) 兩台電腦間無縫切換開發。🐧 Ubuntu 開發流程 (實驗室機台)1. 更新與初始化專案# 進入範例目錄並更新
cd ~/EE2405/code-example
git pull

# 建立新實驗資料夾 (以 labx 為例)
mkdir labx
cd labx

# 建立 Mbed OS 連結與複製必要設定
ln -s ../mbed-os .
cp ../CMakeLists.txt .
cp ../mbed_app.json .
code main.cpp
2. 編譯與燒錄 (Compile & Flash)mkdir build && cd build
cmake .. -GNinja -DMBED_TARGET=B_L4S5I_IOT01A

# 使用 Ninja 進行燒錄
sudo ninja flash-MbedCEHelloWorld
3. 序列埠監控與截圖Monitor: sudo microcom --port=/dev/ttyACM0 --speed=115200Exit: Ctrl-\ 然後按 Ctrl-CScreenshot: gnome-screenshot -d 5 (延遲 5 秒後截圖)🍎 macOS 開發流程 (個人電腦)1. 編譯專案# 在 build 資料夾內執行
ninja MbedCEHelloWorld
2. 手動燒錄 (Flash)由於 Mac 有時無法直接透過 Ninja 燒錄，建議使用手動複製方式：cp MbedCEHelloWorld.bin /Volumes/DIS_L4S5VI/
sync
3. 序列埠監控 (Serial Port)# 確認裝置名稱
ls /dev/cu.usbmodem*

# 使用 minicom 連線 (請根據 ls 結果修改 modem 編號)
minicom -D /dev/cu.usbmodem1103 -b 115200
# To exit: Press Esc + X
🔄 跨平台同步指南 (Git Sync)💡 重要提醒：.gitignore本專案已設定 .gitignore 忽略 build/ 與 mbed-os/（連結）。切換電腦後：請務必重新執行 mkdir build && cmake ..，因為 Mac 與 Linux 的路徑編譯檔不相容。📤 在電腦 A 完成開發後：git add .
git commit -m "feat: 完成 Lab X 功能"
git push origin main
📥 在電腦 B 開始作業前：git pull origin main
# 刪除舊的 build 並重新建立
rm -rf build && mkdir build && cd build
cmake .. -GNinja -DMBED_TARGET=B_L4S5I_IOT01A
📂 專案結構建議mbed-os/: 核心庫 (透過 ln -s 連結)。.gitignore: 排除大型二進位檔與暫存資料夾。main.cpp: 各實驗的主程式。Maintainer: linshangxun
---

### 🚀 如何更新你的 GitHub 專案？

1.  **在 Ubuntu 終端機執行**：
    ```bash
    cd ~/EE2405
    nano README.md  # 貼上上面的內容並存檔
    ```
2.  **上傳到雲端**：
    ```bash
    git add README.md
    git commit -m "docs: 根據 Ubuntu 和 Mac 流程更新 README"
    git push origin main
