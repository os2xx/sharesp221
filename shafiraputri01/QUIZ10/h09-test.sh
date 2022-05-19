#!/bin/bash
# REV01 Sun 15 May 2022 18:30:00 WIB
# START Sat 14 May 2022 23:00:00 WIB
# Copy this file into the github.com repo.

WEEK="10"
export PATH="$HOME/bin/:$PATH"
error() {
    echo "ZCZC ERROR $@" | tee -a $FILE
    exit 1
}
fecho(){
    echo "ZCZC $@" | tee -a $FILE
    sleep 1
    sync
}
FILE="/tmp/WEEK$WEEK-MODULE-LOG.txt"
[ -f $FILE           ] && /bin/rm -f $FILE
[ -d testfs/         ] || fecho MKDIR $(mkdir -pv testfs/)
[ -b /dev/sdc        ] || error /dev/sdd is not a block device!
[ -x ./mkfs.simplefs ] || error can not execute ./mkfs.simplefs
fecho DDCLEAN $(dd if=/dev/zero of=/dev/sdc bs=1M count=10)
fecho MKFS    $(./mkfs.simplefs /dev/sdc)
fecho MOUNT   $(mount -t simplefs /dev/sdc testfs/)
fecho DF      $(df|grep sdc)
fecho PWD1    $(pwd)
fecho CD1
cd testfs/
fecho PWD2    $(pwd)
fecho FILE1   $(touch file1.txt)
fecho FILE2   $(echo "=====">file2.txt;echo "This is file2.txt" >> file2.txt;echo "=====">>file2.txt)
fecho FILE3   $(touch file3.txt)
fecho LSAL
ls -al        | tee -a $FILE
fecho CAT file2.txt
cat file2.txt | tee -a $FILE
fecho PWD3    $(pwd)
fecho CD2
cd ../
fecho PWD4    $(pwd)
fecho UMOUNT $(umount /dev/sdc)
[ -d testfs/ ]         && fecho RMDIR $(rm -rf testfs/)
fecho ===== RESULT IN $FILE =====
fecho ===== chown the file and move it to "SP_RESULT/W$WEEK/"