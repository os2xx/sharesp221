#!/bin/bash
# 27:1F6C47A9
# REV02: Wed 09 Mar 2022 23:30:00 WIB
# REV01: Mon 21 Feb 2022 17:30:00 WIB
# START: Sat 06 Nov 2021 17:47:10 WIB

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
SEQ="02"
FILE="$WEEKDIR/WEEK$WEEK-$SEQ-LFS11-ALL-in-ONE.txt"
[ -f $FILE      ] && /bin/rm -f $FILE
[ -d $HOME/bin/ ] || mkdir -pv $HOME/bin/
[ -d $WEEKDIR/  ] || mkdir -pv $WEEKDIR/

fecho DOWNLOAD LFS11.0 $(wget -c --load-cookies /tmp/cookies.txt "https://docs.google.com/uc?export=download&confirm=$(wget --quiet --save-cookies /tmp/cookies.txt --keep-session-cookies --no-check-certificate 'https://docs.google.com/uc?export=download&id=1tfJ-NZYOy-h3jc_LDswlIMvfftaNkEm8' -O- | sed -rn 's/.*confirm=([0-9A-Za-z_]+).*/\1\n/p')&id=1tfJ-NZYOy-h3jc_LDswlIMvfftaNkEm8" -O $TARBALL && rm -rf /tmp/cookies.txt)
[ -f $TARBALL ] || error "TRY DOWNLOAD AGAIN ==== ==== ===="
[ -f $TARBALL ] && {
    tar tf $TARBALL | tee -a $FILE
    fecho SIZE $(du -s -h $TARBALL)
}

fecho SCRIPT    $(head -3 $0 | tail -1)
fecho STAMPX    $(mkSTAMP)
fecho VERSUM    $(versum $0)
fecho WEEKXX    $WEEK $SEQ
fecho VERDSK    $(verdisk)
fecho VERLNX    $(verkernel)
fecho PATHXX    $(echo $PATH|grep -Eo \/home\/$(whoami)\/bin) IS OK
fecho hoBIN $(ls $HOME/bin/[0-9][0-9]-SP-*)
fecho ===== RESULT IN $FILE =====

exit 0

