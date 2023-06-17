# imx6-sdk
用于ixm6ull baremetal开发环境

arm-gcc工具栏版本为7.3.1

/* 全局修改 */
vim /etc/profile

/* 下面路径为arm-none-eabi-gcc 交叉工具链所在路径 */
export ARMGCC_DIR=/usr/local/arm/gcc-arm-none-eabi-7-2018-q2-update/

/* 立即生效 */
source /etc/profile
