#!/usr/bin/env bash

 #
 # Script to Generating/updating all device's defconfig
 #

##----------------------------------------------------------##

MI=vendor/xiaomi
LAV=arch/arm64/configs/lavender_defconfig

##----------------------------------------------------------##

# jason, platina, wayne
DEVICES=(
	tulip
	whyred
)

##----------------------------------------------------------##

for i in "${DEVICES[@]}"
do
	cp $LAV arch/arm64/configs/${i}_defconfig
	make ARCH=arm64 ${i}_defconfig $MI/RmLav.config $MI/${i}.config
	make ARCH=arm64 savedefconfig
	mv out/.config arch/arm64/configs/${i}_defconfig
done

##----------------------------------------------------------##

git add .
git commit -sm "configs: xiaomi: sync with lavender defconfig"
