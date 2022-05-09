#/bin/bash

PACK="apt"
USER="hjl"
# add new USER hjl
# sudo adduser ${USER}
# sudo usermod -aG sudo ${USER}
# su hjl
# USER="$(whoami)"
# echo $USER
if [[ $(whoami) != ${USER} ]];then
    echo "Change to user ${USER} failed"
    exit 1
else
    echo "Add user $(whoami) Succeed"
fi

# init all package
sudo ${PACK} update
PACKLIST="g++ gcc git make cmake ssh zsh autojump bat"
sudo ${PACK} install ${PACKLIST}

# set git config
# git config --global user.name "$(uname -n)" 
# git config --global user.email "1196455147@qq.com"

GITIP="# The following lien are fo github hjl
140.82.113.3 github.com
199.232.69.194 github.global.ssl.fastly.net
185.199.108.153 assets-cdn.github.com
185.199.109.153 assets-cdn.github.com
185.199.110.153 assets-cdn.github.com
185.199.111.153 assets-cdn.github.com
185.199.108.133 raw.githubusercontent.com
185.199.109.133 raw.githubusercontent.com
185.199.110.133 raw.githubusercontent.com
185.199.111.133 raw.githubusercontent.com
#2606:50c0:8000::153 assets-cdn.github.com
#2606:50c0:8001::153 assets-cdn.github.com
#2606:50c0:8002::153 assets-cdn.github.com
#2606:50c0:8003::153 assets-cdn.github.com"
if ! grep -q "github" /etc/hosts;then
    echo "Not found Github ip in hosts, So add it."
    sudo echo ${GITIP} >> /etc/hosts
fi
# sudo systemctl is-active systemd-resolved
# sudo systemd-resolve --statistics
sudo systemd-resolve --flush-caches

# 1. add public key
# 2. upload private key
ssh -T git@github.com # 确保能够访问

# ready for zsh
OMZ=~/.oh-my-zsh/
if [[ -d "${OMZ}" ]];then
    echo "${OMZ} Existed; Either delete or ignore it"
else
    echo "Download ${OMZ}"
    sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
fi

ATS=${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-autosuggestions
if [[ -d "${ATS}" ]];then
    echo ${ATS} " Existed; Either delete or ignore it"
else
    git clone https://github.com/zsh-users/zsh-autosuggestions ${ATS}
fi
SH=${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting
if [[ -d "${SH}" ]];then
    echo ${SH} " Existed; Either delete or ignore it"
else
    git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${SH}
fi

# download shell config such as alias
GitUrl="https://raw.githubusercontent.com/huqianshan/Scraps/main/Config/"
Shell_Prefix=~/
VsCode_Snippets_Prefix=~/AppData/Roaming/Code/User/snippets/

function config_shell() {
    url="${GitUrl}$1"
    if [[ -f "${2}" ]];then
        echo "${2} existed rename ${2}.old"
        mv ${2} ${2}.old
    fi
    curl -o $2 "${url}" > /dev/null 
    source $2
}


Shell_list=(".zshrc")
for shell in ${Shell_list[@]}; do
    config_shell ${shell} ${Shell_Prefix}${shell}
    echo "${Shell_Prefix}${shell}"
done

echo $OSTYPE
#https://stackoverflow.com/questions/394230/how-to-detect-the-os-from-a-bash-script
if [ "$OSTYPE" == "msys" ] || [ "$OSTYPE" == "cygwin" ] || [ "$OSTYPE" == "win32" ]; then
    Snippets_list=("c.json" "cpp.json" "shellscript.json")
    for snip in ${Snippets_list[@]}; do
        config_shell $snip $VsCode_Snippets_Prefix$snip
    done
    config_shell .bashrc ${Shell_Prefix}.bashrc
fi

# config_shell "c.json" ${VsCode_Snipates_Prefix}

