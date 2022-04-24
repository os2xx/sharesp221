#!/bin/bash
# REV05: Mon 18 Apr 2022 19:53:22 WIB
# REV04: Mon 11 Apr 2022 20:03:46 WIB
# REV03: Thu 17 Mar 2022 10:43:06 WIB
# REV02: Mon 28 Feb 2022 19:14:05 WIB
# REV01: Mon 21 Feb 2022 22:00:00 WIB
# START: Sun 20 Feb 2022 16:35:08 WIB

WEEK="07"
WEEKDIR="$HOME/SP_RESULT/W$WEEK"
TARBALL=/var/tmp/LFS-11.0-SOURCES.tar.xz
LFSDIR="/mnt/lfs"
TMPFILE="/tmp/TMPFILE.txt"
CPLIST=""
export PATH="$HOME/bin/:$PATH"
error() {
    echo "ZCZC ERROR $@" | tee -a $FILE
    exit 1
}
fecho(){
    echo "ZCZC $@" | tee -a $FILE
}
mkSTAMP() {
   local EXSTAMP=$(printf "%8.8X" $(( $(date +%s) & 16#FFFFFFFF )) )
   local EXCHSUM="XXXXXXXX"
   [ "$(hostname)" = "$(whoami)" ] && {
       EXCHSUM=$(echo "$USER$EXSTAMP"|sha1sum|tr '[a-z]' '[A-Z]'| cut -c1-8)
   }
   echo  "$EXSTAMP $EXCHSUM $(whoami)"
}
verdisk() {
    df -h /dev/sd?2|tail -2|awk '{print $2}'
    ls -l /dev/disk/by-uuid|awk '/sd[ab]2/ {print $9}'|tr '[a-z]' '[A-Z]'|cut -d- -f5,5
}
verkernel() {
    cat /proc/version | cut -d' ' -f3,3
}
versum() {
    CFILE=$1
    printf "%X:%s " $(tail -n +3 $CFILE|wc -l) $(tail -n +3 $CFILE|sha1sum|cut -c1-8|tr '[a-z]' '[A-Z]')
    head -2 $CFILE|tail -1|cut -c3-
}

