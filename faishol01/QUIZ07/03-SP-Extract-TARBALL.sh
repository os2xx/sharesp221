#!/bin/bash
# 2B:59F67ECA
# REV03: Wed 09 Mar 2022 23:30:00 WIB
# REV02: Mon 21 Feb 2022 18:00:00 WIB
# REV01: Sun 07 Nov 2021 06:34:04 WIB
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
SEQ="03"
FILE="$WEEKDIR/WEEK$WEEK-$SEQ-Extract-TARBALL.txt"
[ -f $FILE      ] && /bin/rm -f $FILE
[ -d $HOME/bin/ ] || mkdir -pv $HOME/bin/
[ -d $WEEKDIR/  ] || mkdir -pv $WEEKDIR/

[ -d $LFSDIR/sources/ ] || error "No $LFSDIR/source/ ==== ===="
pushd $LFSDIR/sources/ &> /dev/null
[ -f $TARBALL ] && tar xvf $TARBALL --no-same-permissions --strip-components 1 | tee -a $FILE
fecho "MD5SUM ERROR $(md5sum -c md5sums | grep -v " OK$" | wc -l)"
popd &> /dev/null

fecho SCRIPT    $(head -3 $0 | tail -1)
fecho STAMPX    $(mkSTAMP)
fecho VERSUM    $(versum $0)
fecho WEEKXX    $WEEK $SEQ
fecho EXTRACT   TARBALL
fecho VERDSK    $(verdisk)
fecho VERLNX    $(verkernel)
fecho PATHXX    $(echo $PATH|grep -Eo \/home\/$(whoami)\/bin) IS OK
fecho hoBIN $(ls $HOME/bin/[0-9][0-9]-SP-*)
fecho "CEK FOLDER $LFSDIR/sources/ ==== ===="
fecho ===== RESULT IN $FILE =====

exit 0




