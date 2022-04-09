#/bin/bash

# sudo adduser hjl
# sudo usermod -aG sudo hjl
# init all
# sudo apt-get g++ gcc clang
# sudo apt-get install git make cmake ssh ssh-server

# sudo apt-get install zsh autojump
# sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
# git clone https://github.com/zsh-users/zsh-autosuggestions ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-autosuggestions
# git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting

# download

GitUrl="https://raw.githubusercontent.com/huqianshan/Scraps/main/Config/"
Shell_Prefix=~/
VsCode_Snippets_Prefix=~/AppData/Roaming/Code/User/snippets/

function config_shell() {
    url="${GitUrl}$1"
    curl -o $2 "${url}" > /dev/null 
}

ssh -T git@github.com # 确保能够访问
Shell_list=(".zshrc")
for shell in ${Shell_list[@]}; do
    config_shell $shell ${Shell_Prefix}${shell}
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
