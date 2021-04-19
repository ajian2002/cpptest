export hostIP=`grep -oP  "(\d+\.)+(\d+)" /etc/resolv.conf`
sudo sed -i "115c http $hostIP 10081" /etc/proxychains4.conf
sudo sed -i "116c socks5 $hostIP 10080" /etc/proxychains4.conf
