= imximage.cfg.gz =
; reuse the i.MX6ULL cfg file for the UL EVK ... seems to work
git clone git://git.denx.de/u-boot.git u-boot/
pushd u-boot
git checkout 3cfb67d0419c645998b440592d8c2ce010134b8e
popd u-boot

cp u-boot/board/freescale/mx6ullevk/imximage.cfg .

