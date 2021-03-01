#!/bin/bash
#made by githubuser addei
#GPL 2.0

declare -a dependencies=("make" "gpio" "gcc" "sudo")
destination="/opt/bin/ipv4_16x2"
filename="ipv4_16x2"
readonly cronline="* * 01-31 * * /opt/bin/ipv4_16x2/./ipv4_16x2"


build() {
    if [ ! -f "$makefile" ] ; then
        if make
        
        then
        echo "Build ok!"
        
        else
        echo "Build error!"
        exit 1
        fi
        
    else
        echo "Error! Makefile missing!"
        exit 1
    fi
}

checkDependencies() { #this function checks if the required dependencies are found 
    declare -i flag=0
    for i in "${dependencies[@]}"
    do
        if ! type $i >/dev/null ; then
            if [ $flag -eq 0 ] ; then
                flag=1
            fi
            echo "$i is missing"
        fi
    done
    if [ ! $flag -eq 0 ] ; then
        echo "You need to have following dependencies installed: ${dependencies[*]}"
        exit 1
    fi
}

createInstFolder() { #this function checks if the folder for the installation is present and if not it creates it
    if [ ! -d "$destination" ] ; then
        echo "Installation folder does not exists"
        echo "Creating it now!"
        sudo mkdir -p $destination
    else
        echo "Installation folder exists already."
    fi
}

cronjob() {
    # crontab
    #write out current crontab
    crontab -l > /tmp/mycron
    
    if grep -Fxq "$cronline" /tmp/mycron > /dev/null
    then
        echo "Cronjob already exists for the user!"
    else
        #echo new cron into cron file
        #echo "* * 01-31 * * /opt/bin/$filename/./$filename" >> /tmp/mycron
        echo "$cronline" >> /tmp/mycron
        #install new cron file
        crontab /tmp/mycron
        echo "Creating cronjob!"
    fi

    rm /tmp/mycron

}

installProg() {
    # install
    sudo cp ipv4_16x2 $destination
}



path() {
    # path
    export PATH=$PATH:~/opt/bin
}


checkDependencies
build
createInstFolder
installProg
cronjob






