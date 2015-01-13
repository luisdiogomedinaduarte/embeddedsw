/*******************************************************************************
 *
 * Copyright (C) 2015 Xilinx, Inc.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * Use of the Software is limited solely to applications:
 * (a) running on a Xilinx device, or
 * (b) that interact with a Xilinx device through a bus or interconnect.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * XILINX CONSORTIUM BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Except as contained in this notice, the name of the Xilinx shall not be used
 * in advertising or otherwise to promote the sale, use or other dealings in
 * this Software without prior written authorization from Xilinx.
 *
*******************************************************************************/
/******************************************************************************/
/**
 *
 * @file xvid_timings_table.c
 *
 * Contains video timings for various standard resolutions.
 *
 * @note	None.
 *
 * <pre>
 * MODIFICATION HISTORY:
 *
 * Ver   Who  Date     Changes
 * ----- ---- -------- -----------------------------------------------
 * 1.0   als, 01/10/15 Initial release.
 *       rc
 * </pre>
 *
*******************************************************************************/

/******************************* Include Files ********************************/

#include "xvid.h"

/**************************** Variable Definitions ****************************/

/**
 * This table contains the main stream attributes for various standard
 * resolutions. Each entry is of the format:
 * 1) ID: XVID_VM_<HRES>x<VRES>_<FRAME RATE (HZ)>_<P|I>(_RB = Reduced Blanking)
 * 2) Resolution naming: "<HRES>x<VRES>@<FRAME RATE (HZ)>"
 * 3) Frame rate: XVID_FR_<FRAME RATE (HZ)>
 * 4) Video timing structure:
 *    1) Horizontal active resolution (pixels)
 *    2) Horizontal front porch (pixels)
 *    3) Horizontal sync width (pixels)
 *    4) Horizontal back porch (pixels)
 *    5) Horizontal total (pixels)
 *    6) Horizontal sync polarity (0=negative|1=positive)
 *    7) Vertical active resolution (lines)
 *    8) Frame 0: Vertical front porch (lines)
 *    9) Frame 0: Vertical sync width (lines)
 *    10) Frame 0: Vertical back porch (lines)
 *    11) Frame 0: Vertical total (lines)
 *    12) Frame 1: Vertical front porch (lines)
 *    13) Frame 1: Vertical sync width (lines)
 *    14) Frame 1: Vertical back porch (lines)
 *    15) Frame 1: Vertical total (lines)
 *    16) Vertical sync polarity (0=negative|1=positive)
 */
const XVid_VideoTimingMode XVid_VideoTimingModes[XVID_VM_NUM_SUPPORTED] =
{
	/* Interlaced modes. */
	{ XVID_VM_480_30_I, "720x480@30Hz (I)", XVID_FR_30HZ,
		{720, 19, 62, 57, 858, 0,
		240, 4, 3, 15, 262, 4, 3, 16, 263, 0} },
	{ XVID_VM_576_25_I, "720x576@25Hz (I)", XVID_FR_25HZ,
		{720, 12, 63, 69, 864, 0,
		288, 2, 3, 19, 312, 2, 3, 20, 313, 0} },
	{ XVID_VM_1080_25_I, "1920x1080@25Hz (I)", XVID_FR_25HZ,
		{1920, 88, 44, 148, 2200, 1,
		540, 2, 5, 15, 562, 2, 5, 16, 563, 1} },
	{ XVID_VM_1080_30_I, "1920x1080@30Hz (I)", XVID_FR_30HZ,
		{1920, 88, 44, 148, 2200, 1,
		540, 2, 5, 15, 562, 2, 5, 16, 563, 1} },

	/* Progressive modes. */
	{ XVID_VM_640x350_85_P, "640x350@85Hz", XVID_FR_85HZ,
		{640, 32, 64, 96, 832, 1,
		350, 32, 3, 60, 445, 0, 0, 0, 0, 0} },
	{ XVID_VM_640x480_60_P, "640x480@60Hz", XVID_FR_60HZ,
		{640, 8+8, 96, 40+8, 800, 0,
		480, 2+8, 2, 25+8, 525, 0, 0, 0, 0, 0} },
	{ XVID_VM_640x480_72_P, "640x480@72Hz", XVID_FR_72HZ,
		{640, 8+16, 40, 120+8, 832, 0,
		480, 8+1, 3, 20+8, 520, 0, 0, 0, 0, 0} },
	{ XVID_VM_640x480_75_P, "640x480@75Hz", XVID_FR_75HZ,
		{640, 16, 64, 120, 840, 0,
		480, 1, 3, 16, 500, 0, 0, 0, 0, 0} },
	{ XVID_VM_640x480_85_P, "640x480@85Hz", XVID_FR_85HZ,
		{640, 56, 56, 80, 832, 0,
		480, 1, 3, 25, 509, 0, 0, 0, 0, 0} },
	{ XVID_VM_720x400_85_P, "720x400@85Hz", XVID_FR_85HZ,
		{720, 36, 72, 108, 936, 0,
		400, 1, 3, 42, 446, 0, 0, 0, 0, 1} },
	{ XVID_VM_720x480_60_P, "720x480@60Hz", XVID_FR_60HZ,
		{720, 16, 62, 60, 858, 0,
		480, 9, 6, 30, 525, 0, 0, 0, 0, 0} },
	{ XVID_VM_800x600_56_P, "800x600@56Hz", XVID_FR_56HZ,
		{800, 24, 72, 128, 1024, 1,
		600, 1, 2, 22, 625, 0, 0, 0, 0, 1} },
	{ XVID_VM_800x600_60_P, "800x600@60Hz", XVID_FR_60HZ,
		{800, 40, 128, 88, 1056, 1,
		600, 1, 4, 23, 628, 0, 0, 0, 0, 1} },
	{ XVID_VM_800x600_72_P, "800x600@72Hz", XVID_FR_72HZ,
		{800, 56, 120, 64, 1040, 1,
		600, 37, 6, 23, 666, 0, 0, 0, 0, 1} },
	{ XVID_VM_800x600_75_P, "800x600@75Hz", XVID_FR_75HZ,
		{800, 16, 80, 160, 1056, 1,
		600, 1, 3, 21, 625, 0, 0, 0, 0, 1} },
	{ XVID_VM_800x600_85_P, "800x600@85Hz", XVID_FR_85HZ,
		{800, 32, 64, 152, 1048, 1,
		600, 1, 3, 27, 631, 0, 0, 0, 0, 1} },
	{ XVID_VM_800x600_120_P_RB, "800x700@120Hz (RB)", XVID_FR_120HZ,
		{800, 48, 32, 80, 960, 1,
		600, 3, 4, 29, 636, 0, 0, 0, 0, 0} },
	{ XVID_VM_848x480_60_P, "848x480@60Hz", XVID_FR_60HZ,
		{848, 16, 112, 112, 1088, 1,
		480, 6, 8, 23, 517, 0, 0, 0, 0, 1} },
	{ XVID_VM_1024x768_60_P, "1024x768@60Hz", XVID_FR_60HZ,
		{1024, 24, 136, 160, 1344, 0,
		768, 3, 6, 29, 806, 0, 0, 0, 0, 0} },
	{ XVID_VM_1024x768_70_P, "1024x768@70Hz", XVID_FR_70HZ,
		{1024, 24, 136, 144, 1328, 0,
		768, 3, 6, 29, 806, 0, 0, 0, 0, 0} },
	{ XVID_VM_1024x768_75_P, "1024x768@75Hz", XVID_FR_75HZ,
		{1024, 16, 96, 176, 1312, 1,
		768, 1, 3, 28, 800, 0, 0, 0, 0, 1} },
	{ XVID_VM_1024x768_85_P, "1024x768@85Hz", XVID_FR_85HZ,
		{1024, 48, 96, 208, 1376, 1,
		768, 1, 3, 36, 808, 0, 0, 0, 0, 1} },
	{ XVID_VM_1024x768_120_P_RB, "1024x768@120Hz (RB)", XVID_FR_120HZ,
		{1024, 48, 32, 80, 1184, 1,
		768, 3, 4, 38, 813, 0, 0, 0, 0, 0} },
	{ XVID_VM_1152x864_75_P, "1152x864@75Hz", XVID_FR_75HZ,
		{1152, 64, 128, 256, 1600, 1,
		864, 1, 3, 32, 900, 0, 0, 0, 0, 1} },
	{ XVID_VM_1280x720_50_P, "1280x720@50Hz", XVID_FR_50HZ,
		{1280, 440, 40, 220, 1980, 0,
		720, 5, 5, 20, 750, 0, 0, 0, 0, 0} },
	{ XVID_VM_1280x720_60_P, "720p@60Hz", XVID_FR_60HZ,
		{1280, 110, 40, 220, 1650, 0,
		720, 5, 5, 20, 750, 0, 0, 0, 0, 0} },
	{ XVID_VM_1280x768_60_P_RB, "1280x768@60Hz (RB)", XVID_FR_60HZ,
		{1280, 48, 32, 80, 1440, 1,
		768, 3, 7, 12, 790, 0, 0, 0, 0, 0} },
	{ XVID_VM_1280x768_60_P, "1280x768@60Hz", XVID_FR_60HZ,
		{1280, 64, 128, 192, 1664, 0,
		768, 3, 7, 20, 798, 0, 0, 0, 0, 1} },
	{ XVID_VM_1280x768_75_P, "1280x768@75Hz", XVID_FR_75HZ,
		{1280, 80, 128, 208, 1696, 0,
		768, 3, 7, 27, 805, 0, 0, 0, 0, 1} },
	{ XVID_VM_1280x768_85_P, "1280x768@85Hz", XVID_FR_85HZ,
		{1280, 80, 136, 216, 1712, 0,
		768, 3, 7, 31, 809, 0, 0, 0, 0, 1} },
	{ XVID_VM_1280x768_120_P_RB, "1280x768@120Hz (RB)", XVID_FR_120HZ,
		{1280, 48, 32, 80, 1440, 1,
		768, 3, 7, 35, 813, 0, 0, 0, 0, 0} },
	{ XVID_VM_1280x800_60_P_RB, "1280x800@60Hz (RB)", XVID_FR_60HZ,
		{1280, 48, 32, 80, 1440, 1,
		800, 3, 6, 14, 823, 0, 0, 0, 0, 0} },
	{ XVID_VM_1280x800_60_P, "1280x800@60Hz", XVID_FR_60HZ,
		{1280, 72, 128, 200, 1680, 0,
		800, 3, 6, 22, 831, 0, 0, 0, 0, 1} },
	{ XVID_VM_1280x800_75_P, "1280x800@75Hz", XVID_FR_75HZ,
		{1280, 80, 128, 208, 1696, 0,
		800, 3, 6, 29, 838, 0, 0, 0, 0, 1} },
	{ XVID_VM_1280x800_85_P, "1280x800@85Hz", XVID_FR_85HZ,
		{1280, 80, 136, 216, 1712, 0,
		800, 3, 6, 34, 843, 0, 0, 0, 0, 1} },
	{ XVID_VM_1280x800_120_P_RB, "1280x800@120Hz (RB)", XVID_FR_120HZ,
		{1280, 48, 32, 80, 1440, 1,
		800, 3, 6, 38, 847, 0, 0, 0, 0, 0} },
	{ XVID_VM_1280x960_60_P, "1280x960@60Hz", XVID_FR_60HZ,
		{1280, 96, 112, 312, 1800, 1,
		960, 1, 3, 36, 1000, 0, 0, 0, 0, 1} },
	{ XVID_VM_1280x960_85_P, "1280x960@85Hz", XVID_FR_85HZ,
		{1280, 64, 160, 224, 1728, 1,
		960, 1, 3, 47, 1011, 0, 0, 0, 0, 1} },
	{ XVID_VM_1280x960_120_P_RB, "1280x960@120Hz (RB)", XVID_FR_120HZ,
		{1280, 48, 32, 80, 1440, 1,
		960, 3, 4, 50, 1017, 0, 0, 0, 0, 0} },
	{ XVID_VM_1280x1024_60_P, "1280x1024@60Hz", XVID_FR_60HZ,
		{1280, 48, 112, 248, 1688, 1,
		1024, 1, 3, 38, 1066, 0, 0, 0, 0, 1} },
	{ XVID_VM_1280x1024_75_P, "1280x1024@75Hz", XVID_FR_75HZ,
		{1280, 16, 144, 248, 1688, 1,
		1024, 1, 3, 38, 1066, 0, 0, 0, 0, 1} },
	{ XVID_VM_1280x1024_85_P, "1280x1024@85Hz", XVID_FR_85HZ,
		{1280, 64, 160, 224, 1728, 1,
		1024, 1, 3, 44, 1072, 0, 0, 0, 0, 1} },
	{ XVID_VM_1280x1024_120_P_RB, "1280x1024@120Hz (RB)", XVID_FR_120HZ,
		{1280, 48, 32, 80, 1440, 1,
		1024, 3, 7, 50, 1084, 0, 0, 0, 0, 0} },
	{ XVID_VM_1360x768_60_P, "1360x768@60Hz", XVID_FR_60HZ,
		{1360, 64, 112, 256, 1792, 1,
		768, 3, 6, 18, 795, 0, 0, 0, 0, 1} },
	{ XVID_VM_1360x768_120_P_RB, "1360x768@120Hz (RB)", XVID_FR_120HZ,
		{1360, 48, 32, 80, 1520, 1,
		768, 3, 5, 37, 813, 0, 0, 0, 0, 0} },
	{ XVID_VM_1366x768_60_P, "1366x768@60Hz", XVID_FR_60HZ,
		{1366, 14, 56, 64, 1500, 1,
		768, 1, 3, 28, 800, 0, 0, 0, 0, 1} },
	{ XVID_VM_1400x1050_60_P_RB, "1400x1050@60Hz (RB)", XVID_FR_60HZ,
		{1400, 48, 32, 80, 1560, 1,
		1050, 3, 4, 23, 1080, 0, 0, 0, 0, 0} },
	{ XVID_VM_1400x1050_60_P, "1400x1050@60Hz", XVID_FR_60HZ,
		{1400, 88, 144, 232, 1864, 0,
		1050, 3, 4, 32, 1089, 0, 0, 0, 0, 1} },
	{ XVID_VM_1400x1050_75_P, "1400x1050@75Hz", XVID_FR_75HZ,
		{1400, 104, 144, 248, 1896, 0,
		1050, 3, 4, 42, 1099, 0, 0, 0, 0, 1} },
	{ XVID_VM_1400x1050_85_P, "1400x1050@85Hz", XVID_FR_85HZ,
		{1400, 104, 152, 256, 1912, 0,
		1050, 3, 4, 48, 1105, 0, 0, 0, 0, 1} },
	{ XVID_VM_1400x1050_120_P_RB, "1400x1050@120Hz (RB)", XVID_FR_120HZ,
		{1400, 48, 32, 80, 1560, 1,
		1050, 3, 4, 55, 1112, 0, 0, 0, 0, 0} },
	{ XVID_VM_1440x900_60_P_RB, "1440x900@60Hz (RB)", XVID_FR_60HZ,
		{1440, 48, 32, 80, 1600, 1,
		900, 3, 6, 17, 926, 0, 0, 0, 0, 0} },
	{ XVID_VM_1440x900_60_P, "1440x900@60Hz", XVID_FR_60HZ,
		{1440, 80, 152, 232, 1904, 0,
		900, 3, 6, 25, 934, 0, 0, 0, 0, 1} },
	{ XVID_VM_1440x900_75_P, "1440x900@75Hz", XVID_FR_75HZ,
		{1440, 96, 152, 248, 1936, 0,
		900, 3, 6, 33, 942, 0, 0, 0, 0, 1} },
	{ XVID_VM_1440x900_85_P, "1440x900@85Hz", XVID_FR_85HZ,
		{1440, 104, 152, 256, 1952, 0,
		900, 3, 6, 39, 948, 0, 0, 0, 0, 1} },
	{ XVID_VM_1440x900_120_P_RB, "1440x900@120Hz (RB)", XVID_FR_120HZ,
		{1440, 48, 32, 80, 1600, 1,
		900, 3, 6, 44, 953, 0, 0, 0, 0, 0} },
	{ XVID_VM_1600x1200_60_P, "1600x1200@60Hz", XVID_FR_60HZ,
		{1600, 64, 192, 304, 2160, 1,
		1200, 1, 3, 46, 1250, 0, 0, 0, 0, 1} },
	{ XVID_VM_1600x1200_65_P, "1600x1200@65Hz", XVID_FR_65HZ,
		{1600, 64, 192, 304, 2160, 1,
		1200, 1, 3, 46, 1250, 0, 0, 0, 0, 1} },
	{ XVID_VM_1600x1200_70_P, "1600x1200@70Hz", XVID_FR_70HZ,
		{1600, 64, 192, 304, 2160, 1,
		1200, 1, 3, 46, 1250, 0, 0, 0, 0, 1} },
	{ XVID_VM_1600x1200_75_P, "1600x1200@75Hz", XVID_FR_75HZ,
		{1600, 64, 192, 304, 2160, 1,
		1200, 1, 3, 46, 1250, 0, 0, 0, 0, 1} },
	{ XVID_VM_1600x1200_85_P, "1600x1200@85Hz", XVID_FR_85HZ,
		{1600, 64, 192, 304, 2160, 1,
		1200, 1, 3, 46, 1250, 0, 0, 0, 0, 1} },
	{ XVID_VM_1600x1200_120_P_RB, "1600x1200@120Hz (RB)", XVID_FR_120HZ,
		{1600, 48, 32, 80, 1760, 1,
		1200, 3, 4, 64, 1271, 0, 0, 0, 0, 0} },
	{ XVID_VM_1680x1050_60_P_RB, "1680x1050@60Hz (RB)", XVID_FR_60HZ,
		{1680, 48, 32, 80, 1840, 1,
		1050, 3, 6, 21, 1080, 0, 0, 0, 0, 0} },
	{ XVID_VM_1680x1050_60_P, "1680x1050@60Hz", XVID_FR_60HZ,
		{1680, 104, 176, 280, 2240, 0,
		1050, 3, 6, 30, 1089, 0, 0, 0, 0, 1} },
	{ XVID_VM_1680x1050_75_P, "1680x1050@75Hz", XVID_FR_75HZ,
		{1680, 120, 176, 296, 2272, 0,
		1050, 3, 6, 40, 1099, 0, 0, 0, 0, 1} },
	{ XVID_VM_1680x1050_85_P, "1680x1050@85Hz", XVID_FR_85HZ,
		{1680, 128, 176, 304, 2288, 0,
		1050, 3, 6, 46, 1105, 0, 0, 0, 0, 1} },
	{ XVID_VM_1680x1050_120_P_RB, "1680x1050@120Hz (RB)", XVID_FR_120HZ,
		{1680, 48, 32, 80, 1840, 1,
		1050, 3, 6, 53, 1112, 0, 0, 0, 0, 0} },
	{ XVID_VM_1792x1344_60_P, "1792x1344@60Hz", XVID_FR_60HZ,
		{1792, 128, 200, 328, 2448, 0,
		1344, 1, 3, 46, 1394, 0, 0, 0, 0, 1} },
	{ XVID_VM_1792x1344_75_P, "1792x1344@75Hz", XVID_FR_75HZ,
		{1792, 96, 216, 352, 2456, 0,
		1344, 1, 3, 69, 1417, 0, 0, 0, 0, 1} },
	{ XVID_VM_1792x1344_120_P_RB, "1792x1344@120Hz (RB)", XVID_FR_120HZ,
		{1792, 48, 32, 80, 1952, 1,
		1344, 3, 4, 72, 1423, 0, 0, 0, 0, 0} },
	{ XVID_VM_1856x1392_60_P, "1856x1392@60Hz", XVID_FR_60HZ,
		{1856, 96, 224, 352, 2528, 0,
		1392, 1, 3, 43, 1439, 0, 0, 0, 0, 1} },
	{ XVID_VM_1856x1392_75_P, "1856x1392@75Hz", XVID_FR_75HZ,
		{1856, 128, 224, 352, 2560, 0,
		1392, 1, 3, 104, 1500, 0, 0, 0, 0, 1} },
	{ XVID_VM_1856x1392_120_P_RB, "1856x1392@120Hz (RB)", XVID_FR_120HZ,
		{1856, 48, 32, 80, 2016, 1,
		1392, 3, 4, 75, 1474, 0, 0, 0, 0, 0} },
	{ XVID_VM_1920x1080_24_P, "1920x1080@24Hz", XVID_FR_24HZ,
		{1920, 638, 44, 148, 2750, 0,
		1080, 4, 5, 36, 1125, 0, 0, 0, 0, 0} },
	{ XVID_VM_1920x1080_25_P, "1920x1080@25Hz", XVID_FR_25HZ,
		{1920, 528, 44, 148, 2640, 0,
		1080, 4, 5, 36, 1125, 0, 0, 0, 0, 0} },
	{ XVID_VM_1920x1080_30_P, "1920x1080@30Hz", XVID_FR_30HZ,
		{1920, 88, 44, 148, 2200, 0,
		1080, 4, 5, 36, 1125, 0, 0, 0, 0, 0} },
	{ XVID_VM_1920x1080_50_P, "1920x1080@50Hz", XVID_FR_50HZ,
		{1920, 528, 44, 148, 2640, 0,
		1080, 4, 5, 36, 1125, 0, 0, 0, 0, 0} },
	{ XVID_VM_1920x1080_60_P, "1920x1080@60Hz", XVID_FR_60HZ,
		{1920, 88, 44, 148, 2200, 0,
		1080, 4, 5, 36, 1125, 0, 0, 0, 0, 0} },
	{ XVID_VM_1920x1200_60_P_RB, "1920x1200@60Hz (RB)", XVID_FR_60HZ,
		{1920, 48, 32, 80, 2080, 1,
		1200, 3, 6, 26, 1235, 0, 0, 0, 0, 0} },
	{ XVID_VM_1920x1200_60_P, "1920x1200@60Hz", XVID_FR_60HZ,
		{1920, 136, 200, 336, 2592, 0,
		1200, 3, 6, 36, 1245, 0, 0, 0, 0, 1} },
	{ XVID_VM_1920x1200_75_P, "1920x1200@75Hz", XVID_FR_75HZ,
		{1920, 136, 208, 344, 2608, 0,
		1200, 3, 6, 46, 1255, 0, 0, 0, 0, 1} },
	{ XVID_VM_1920x1200_85_P, "1920x1200@85Hz", XVID_FR_85HZ,
		{1920, 144, 208, 352, 2624, 0,
		1200, 3, 6, 53, 1262, 0, 0, 0, 0, 1} },
	{ XVID_VM_1920x1200_120_P_RB, "1920x1200@120Hz (RB)", XVID_FR_120HZ,
		{1920, 48, 32, 80, 2080, 1,
		1200, 3, 6, 62, 1271, 0, 0, 0, 0, 0} },
	{ XVID_VM_1920x1440_60_P, "1920x1440@60Hz", XVID_FR_60HZ,
		{1920, 128, 208, 344, 2600, 0,
		1440, 1, 3, 56, 1500, 0, 0, 0, 0, 1} },
	{ XVID_VM_1920x1440_75_P, "1920x1440@75Hz", XVID_FR_75HZ,
		{1920, 144, 224, 352, 2640, 0,
		1440, 1, 3, 56, 1500, 0, 0, 0, 0, 1} },
	{ XVID_VM_1920x1440_120_P_RB, "1920x1440@120Hz (RB)", XVID_FR_120HZ,
		{1920, 48, 32, 80, 2080, 1,
		1440, 3, 4, 78, 1525, 0, 0, 0, 0, 0} },
	{ XVID_VM_1920x2160_60_P, "1920x2160@60Hz", XVID_FR_60HZ,
		{1920, 88, 44, 148, 2200, 1,
		2160, 20, 10, 60, 2250, 0, 0, 0, 0, 0} },
	{ XVID_VM_2560x1600_60_P_RB, "2560x1600@60Hz (RB)", XVID_FR_60HZ,
		{2560, 48, 32, 80, 2720, 1,
		1600, 3, 6, 37, 1646, 0, 0, 0, 0, 0} },
	{ XVID_VM_2560x1600_60_P, "2560x1600@60Hz", XVID_FR_60HZ,
		{2560, 192, 280, 472, 3504, 0,
		1600, 3, 6, 49, 1658, 0, 0, 0, 0, 1} },
	{ XVID_VM_2560x1600_75_P, "2560x1600@75Hz", XVID_FR_75HZ,
		{2560, 208, 280, 488, 3536, 0,
		1600, 3, 6, 63, 1672, 0, 0, 0, 0, 1} },
	{ XVID_VM_2560x1600_85_P, "2560x1600@85Hz", XVID_FR_85HZ,
		{2560, 208, 280, 488, 3536, 0,
		1600, 3, 6, 73, 1682, 0, 0, 0, 0, 1} },
	{ XVID_VM_2560x1600_120_P_RB, "2560x1600@120Hz (RB)", XVID_FR_120HZ,
		{2560, 48, 32, 80, 2720, 1,
		1600, 3, 6, 85, 1694, 0, 0, 0, 0, 0} },
	{ XVID_VM_3840x2160_24_P, "3840x2160@24Hz", XVID_FR_24HZ,
		{3840, 1276, 88, 296, 5500, 0,
		2160, 8, 10, 72, 2250, 0, 0, 0, 0, 0} },
	{ XVID_VM_3840x2160_25_P, "3840x2160@25Hz", XVID_FR_25HZ,
		{3840, 1056, 88, 296, 5280, 0,
		2160, 8, 10, 72, 2250, 0, 0, 0, 0, 0} },
	{ XVID_VM_3840x2160_30_P, "3840x2160@30Hz", XVID_FR_30HZ,
		{3840, 176, 88, 296, 4400, 1,
		2160, 20, 10, 60, 2250, 0, 0, 0, 0, 0} },
	{ XVID_VM_3840x2160_60_P, "3840x2160@60Hz", XVID_FR_60HZ,
		{3840, 176, 88, 296, 4400, 1,
		2160, 20, 10, 60, 2250, 0, 0, 0, 0, 0} }
};
