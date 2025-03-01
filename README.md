# masters_2025_qual

- コンテストサイト：https://atcoder.jp/contests/masters2025-qual

## 環境構築メモ

### 前提

node.js, yarn をインストール済みであること。

<details>

<summary>node.js, yarn をインストールする方法</summary>

https://nodejs.org/en/download より引用。以下のコマンドを順番に叩けばOK

```bash
# Download and install nvm:
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.40.1/install.sh | bash

# in lieu of restarting the shell
\. "$HOME/.nvm/nvm.sh"

# Download and install Node.js:
nvm install 22

# Verify the Node.js version:
node -v # Should print "v22.14.0".
nvm current # Should print "v22.14.0".

# Download and install Yarn:
corepack enable yarn

# Verify Yarn version:
yarn -v
```

</details>

### 手順

- このリポジトリを以下のコマンドで clone する

```console
$ git clone --recursive git@github.com:siro53/masters_2025_qual.git
```

- ビジュアライザを起動する

初回起動時のみ `YARN_INIT=1` を付けて実行すること

```console
$ (YARN_INIT=1) sh run_visualizer.sh
```

すると、localhost:5173 にてビジュアライザが立ち上がるはず