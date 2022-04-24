#!/bin/bash
# 26:FAAAFC55
# REV03: Wed 09 Mar 2022 23:45:26 WIB
# REV02: Mon 21 Feb 2022 22:30:00 WIB
# REV01: Sun 14 Nov 2021 08:40:00 WIB
# START: Sat 06 Nov 2021 11:47:14 WIB

if   [ -f  98-SP-include.sh ] ; then
    .  ./98-SP-include.sh
elif [ -f  $HOME/bin/98-SP-include.sh ] ; then
    .  $HOME/bin/98-SP-include.sh
else
    echo "98-SP-include.sh not found"
    exit
fi

[[ "$WEEK" != "02" ]] && error Week 02 only

# ZCZC START #### #### #### ####
SEQ="97"
FILE="$WEEKDIR/WEEK$WEEK-$SEQ-LFS-REPORT.txt"
[ -f $FILE      ] && /bin/rm -f $FILE
[ -d $HOME/bin/ ] || mkdir -pv $HOME/bin/
[ -d $WEEKDIR/  ] || mkdir -pv $WEEKDIR/
[ -f $TMPFILE   ] && cat $TMPFILE | tee $FILE

pushd $LFSDIR/sources/ &> /dev/null
fecho "MD5SUM ERROR $(md5sum -c md5sums | grep -v " OK$" | wc -l)"
popd &> /dev/null

fecho SCRIPT    $(head -3 $0 | tail -1)
fecho STAMPX    $(mkSTAMP)
fecho VERSUM    $(versum $0)
fecho WEEKXX    $WEEK
fecho EXTRACT   TARBALL
fecho VERDSK    $(verdisk)
fecho VERLNX    $(verkernel)
fecho PATHXX    $(echo $PATH|grep -Eo \/home\/$(whoami)\/bin) IS OK
fecho hoBIN $(ls $HOME/bin/[0-9][0-9]-SP-*)
fecho ===== RESULT IN $FILE =====

exit 0

