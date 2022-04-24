#!/bin/bash
# 28:321ABEB7
# REV03: Wed 09 Mar 2022 23:00:00 WIB
# REV02: Mon 28 Feb 2022 19:16:54 WIB
# REV01: Mon 21 Feb 2022 16:30:00 WIB
# START: Sat 06 Nov 2021 11:47:14 WIB

SEQ="00"

if   [ -f  98-SP-include.sh ] ; then
    .  ./98-SP-include.sh
elif [ -f  $HOME/bin/98-SP-include.sh ] ; then
    .  $HOME/bin/98-SP-include.sh
else
    echo "98-SP-include.sh not found"
    exit
fi

# ZCZC START #### #### #### ####
FILE="$WEEKDIR/WEEK$WEEK-$SEQ-INSTALL.txt"
[ -f $FILE      ] && /bin/rm -f $FILE
[ -d $HOME/bin/ ] || mkdir -pv $HOME/bin/
[ -d $WEEKDIR/  ] || mkdir -pv $WEEKDIR/
fecho SCRIPT    $(head -3 $0 | tail -1)
fecho STAMPX    $(mkSTAMP)
fecho VERSUM    $(versum $0)
fecho WEEKXX    $WEEK $SEQ
fecho VERDSK    $(verdisk)
fecho VERLNX    $(verkernel)
fecho PATHXX    $(echo $PATH|grep -Eo \/home\/$(whoami)\/bin) IS OK
for II in [0-9][0-9]-*.sh ; do
    if [ -f $II ] ; then
       chmod 755  $II
       cp -f $II $HOME/bin/
       CPLIST="$CPLIST$II "
    fi
done
fecho hoBIN $(ls $HOME/bin/[0-9][0-9]-SP-*)
fecho ===== RESULT IN $FILE =====

exit 0

