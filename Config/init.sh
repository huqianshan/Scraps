#!/bin/bash

PACK="apt"
USER="hjl"

function check_user() {
    if id "${USER}" &>/dev/null; then
        echo "User ${USER} exists."
        return 0
    else
        echo "User ${USER} does not exist."
        return 1
    fi
}

function add_user() {
    if ! check_user; then
        echo "try to create ${USER}.."
        sudo adduser ${USER}
        sudo usermod -aG sudo ${USER}
        su ${USER}
        echo $USER
    fi
}

function set_git_config() {
    git config --global user.name "$(whoami)-$(uname -n)"
    git config --global user.email "hujinlei1999@qq.com"
}

function install_packages() {
    local apps=('git' 'cmake' 'g++' 'ssh' 'make' 'cmake' 'bat' 'zsh' 'iostat' 'sysstat' 'htop' 'ranger' 'fzf')
    sudo apt update
    for app in "${apps[@]}"; do
        sudo apt-get install $(echo $app | sed 's/,//g') -y
    done
    # 设置 /home/hjl/.ssh/id_rsa 的权限
    # chmod 600 /home/hjl/.ssh/id_rsa
}

function setup_oh_my_zsh() {
    local OMZ=~/.oh-my-zsh/
    if [[ -d "${OMZ}" ]]; then
        echo "${OMZ} Existed; Either delete or ignore it"
    else
        echo "Download ${OMZ}"
        yes | sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
    fi
}

function set_default_editor() {
    echo export EDITOR=/usr/bin/vim >>~/.bashrc
    echo export EDITOR=/usr/bin/vim >>~/.zshrc
}

function config_zsh() {
    ATS=${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-autosuggestions
    if [[ -d "${ATS}" ]]; then
        echo ${ATS} " Existed; Either delete or ignore it"
    else
        git clone https://github.com/zsh-users/zsh-autosuggestions ${ATS}
    fi
    SH=${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting
    if [[ -d "${SH}" ]]; then
        echo ${SH} " Existed; Either delete or ignore it"
    else
        git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${SH}
    fi

    # fzf is for the history command.
    FZF="~/.fzf"
    if [[ ! -d "${FZF}" ]]; then
        git clone --depth=1 https://github.com/junegunn/fzf.git ${FZF}
        ${FZF}/install
        echo "NO fzf install it finished"
    fi
}

function update_zshrc() {
    URL="https://raw.githubusercontent.com/huqianshan/Scraps/refs/heads/main/Config/.zshrc"
    curl -o ~/.zshrc ${URL}
    source ~/.zshrc
}

# function config_ranger() {
#    # install ranger plugins https://zhuanlan.zhihu.com/p/105731111
#   PLUGINS=(caca-utils highlight atool w3m poppler mediainfo catdoc docx2txt xlsx2csv)
#   for plugin in ${PLUGINS[@]}; do
#     sudo apt-get install ${plugin} -y
#     ranger --copy-config=all
#     ranger --copy-config=${plugin}
#   done
# }

# download shell config such as alias
# GitUrl="https://raw.githubusercontent.com/huqianshan/Scraps/main/Config/"
# Shell_Prefix=~/
# VsCode_Snippets_Prefix=~/AppData/Roaming/Code/User/snippets/

# function config_shell() {
#   url="${GitUrl}$1"
#   if [[ -f "${2}" ]]; then
#     echo "${2} existed rename ${2}.old"
#     mv ${2} ${2}.old
#   fi
#   curl -o $2 "${url}" >/dev/null
#   source $2
# }

# Shell_list=(".zshrc")
# for shell in ${Shell_list[@]}; do
#   config_shell ${shell} ${Shell_Prefix}${shell}
#   echo "${Shell_Prefix}${shell}"
# done

# echo $OSTYPE
# #https://stackoverflow.com/questions/394230/how-to-detect-the-os-from-a-bash-script
# if [ "$OSTYPE" == "msys" ] || [ "$OSTYPE" == "cygwin" ] || [ "$OSTYPE" == "win32" ]; then
#   Snippets_list=("c.json" "cpp.json" "shellscript.json")
#   for snip in ${Snippets_list[@]}; do
#     config_shell $snip $VsCode_Snippets_Prefix$snip
#   done
#   config_shell .bashrc ${Shell_Prefix}.bashrc
# fi

# config_shell "c.json" ${VsCode_Snipates_Prefix}

#GITIP="# The following lien are fo github hjl
#140.82.113.3 github.com
#199.232.69.194 github.global.ssl.fastly.net
#185.199.108.153 assets-cdn.github.com
#185.199.109.153 assets-cdn.github.com
#185.199.110.153 assets-cdn.github.com
#185.199.111.153 assets-cdn.github.com
#185.199.108.133 raw.githubusercontent.com
#185.199.109.133 raw.githubusercontent.com
#185.199.110.133 raw.githubusercontent.com
#185.199.111.133 raw.githubusercontent.com
#2606:50c0:8000::153 assets-cdn.github.com
#2606:50c0:8001::153 assets-cdn.github.com
#2606:50c0:8002::153 assets-cdn.github.com
#2606:50c0:8003::153 assets-cdn.github.com"
# if ! grep -q "github" /etc/hosts; then
# echo "Not found Github ip in hosts, So add it."
# sudo echo ${GITIP} >>/etc/hosts
# fi
# sudo systemctl is-active systemd-resolved
# sudo systemd-resolve --statistics
# sudo systemd-resolve --flush-caches

# 1
# add_user
# 2
# set_git_config
# 3
# install_packages
# 4
# setup_oh_my_zsh
# 5
# set_default_editor
# 6
# config_zsh
