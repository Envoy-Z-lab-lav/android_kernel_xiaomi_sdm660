/*
 * Copyright (c) 2012-2018 The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef __WLAN_HDD_STATION_INFO_H
#define __WLAN_HDD_STATION_INFO_H

/**
 * DOC: wlan_hdd_station_info_h
 *
 * WLAN Host Device Driver STATION info API specification
 */

#define DISCONNECT_REASON \
	QCA_WLAN_VENDOR_ATTR_GET_STATION_INFO_DRIVER_DISCONNECT_REASON

#ifdef FEATURE_STATION_INFO
/**
 * wlan_hdd_cfg80211_get_station_cmd() - Handle get station vendor cmd
 * @wiphy: corestack handler
 * @wdev: wireless device
 * @data: data
 * @data_len: data length
 *
 * Handles QCA_NL80211_VENDOR_SUBCMD_GET_STATION.
 * Validate cmd attributes and send the station info to upper layers.
 *
 * Return: Success(0) or reason code for failure
 */
int32_t hdd_cfg80211_get_station_cmd(struct wiphy *wiphy,
				     struct wireless_dev *wdev,
				     const void *data,
				     int data_len);

#define FEATURE_STATION_INFO_VENDOR_COMMANDS				\
{									\
	.info.vendor_id = QCA_NL80211_VENDOR_ID,			\
	.info.subcmd = QCA_NL80211_VENDOR_SUBCMD_GET_STATION,		\
	.flags = WIPHY_VENDOR_CMD_NEED_WDEV |				\
		WIPHY_VENDOR_CMD_NEED_NETDEV |				\
		WIPHY_VENDOR_CMD_NEED_RUNNING,				\
	.doit = hdd_cfg80211_get_station_cmd				\
},
#else /* FEATURE_STATION_INFO */
#define FEATURE_STATION_INFO_VENDOR_COMMANDS
#endif /* FEATURE_STATION_INFO */

#endif /* __WLAN_HDD_STATION_INFO_H */

