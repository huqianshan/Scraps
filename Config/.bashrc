alias update="sudo apt-get update"
alias upgrade="sudo apt-get upgrade"
alias install="sudo apt-get install"
alias search="sudo apt-cache search"
alias list="apt list --installed"
alias autorm="sudo apt autoremove"
alias remove="sudo apt remove"
alias targz="tar -xvf"
alias off="sudo shutdown -h now"
alias reboot="sudo reboot"
# git alias
alias clone="git clone --depth=1"
alias pull="git pull"
alias push="git push"
alias fetch="git fetch"
alias status="git status"
alias add="git add --all"
alias commit="git commit -m"
alias checkout="git checkout"
alias log="git log --graph"
alias branch="git branch -a"
alias stash="git stash"

# linux command
alias ll='ls -ahlF'
alias la='ls -Ah'
alias l='ls -CFh'
alias iotop='sudo iotop'

# ranger alias
alias r="ranger"
alias rr="ranger --choosedir=$HOME/.rangerdir; LASTDIR=$(cat $HOME/.rangerdir); cd '$LASTDIR'"
