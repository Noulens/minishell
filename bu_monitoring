#!/bin/bash
ARCH=$(uname -a)
PCPU=$(lscpu | grep "Socket(s):" | wc -l)
VCPU=$(cat /proc/cpuinfo | grep processor | wc -l)
MEM=$(free -m | awk 'NR==2{printf"%s/%sMB (%.2f%%)", $3, $2, $3 * 100 / $2}')
DSKUS=$(df -h --total | awk '$NF=="-"{printf"%d/%dGB (%s)", $3, $2, $5}')
CPULD=$(top -bn1 | grep Cpu | cut -c 11- | awk '{printf"%.1f%%", $1 + $2 + $3}')
BTTIME=$(who -b | xargs | awk '{printf"%s %s", $3, $4}')
LVMP=$(if [ $(lsblk | grep lvm | wc -l) -eq 0 ]; then echo no; else echo yes; fi)
TCPACT=$(cat /proc/net/sockstat | grep TCP | awk '{print $3}')
USRLOG=$(who | wc -l)
IP4=$(hostname -I)
MAC=$(ip a | grep link/ether | awk '{print $2}')
SUDNUM=$(grep COMMAND /var/log/sudo/sudo.log | wc -l)
wall "*************************************************************************************************************** 
	#Architecture:	$ARCH
	#CPU physical:	$PCPU
	#vCPU:		$VCPU
	#Memory Usage:	$MEM
	#Disk Usage:	$DSKUS
	#CPU load:	$CPULD
	#Last boot:	$BTTIME
	#LVM use:	$LVMP
	#Connexion TCP:	$TCPACT
	#User log:	$USRLOG
	#Network:	IP $IP4 ($MAC)
	#Sudo:		$SUDNUM cmd
***************************************************************************************************************"
