Visual Studio Codeで「Ctrl+Shift+V」と押すとプレビュー画面が表示される．

# 参考

* WSL   https://code.visualstudio.com/docs/cpp/config-wsl
* macOS https://code.visualstudio.com/docs/cpp/config-clang-mac
* MinGW https://code.visualstudio.com/docs/cpp/config-mingw
* Linux https://code.visualstudio.com/docs/cpp/config-linux
* Ubuntu on VirtualBox https://ubuntu.com/tutorials/how-to-run-ubuntu-desktop-on-a-virtual-machine-using-virtualbox

# 変更履歴

* デバッグ実行時に外部端末を開かないように設定．
* エディタで強制的にインデントするように設定．
* 環境変数`PATH`を自動設定するように`.vscode/settings.json`を修正．
  * `terminal.integrated.env.windows`
* ディレクトリ名に日本語や空白が入ってもエラーにならないように`.vscode/tasks.json`を修正．
  * `${file}`から`${relativeFile}`に変更．
  * `"cwd": "${workspaceFolder}"`を設定．
  * `${relativeFile}`などにダブルクォートを追加．
  * `cwd`にあわせて`launch.json`も修正．
* `c_cpp_properties.json`を修正．
