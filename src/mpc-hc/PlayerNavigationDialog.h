/*
 * (C) 2010-2015 see Authors.txt
 *
 * This file is part of MPC-HC.
 *
 * MPC-HC is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * MPC-HC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#include <atlcoll.h>
#include "resource.h"
#include "ResizableLib/ResizableDialog.h"

class CMainFrame;

class CNavListBox : public CListBox
{
public:
    virtual ~CNavListBox() = default;

protected:
    virtual ULONG GetGestureStatus(CPoint) override { return 0; }
};

class CPlayerNavigationDialog : public CResizableDialog
{
private:
    CNavListBox m_channelList;
    CButton m_buttonInfo;
    CButton m_buttonTools;

    CMainFrame* m_pMainFrame;
    bool m_bChannelInfoAvailable;
    bool m_bTVStations;
    int m_tabDVB;
    int m_tabIPTV;
    int m_tabRadio;

public:
    CPlayerNavigationDialog() = delete;
    CPlayerNavigationDialog(CMainFrame* pMainFrame);
    virtual ~CPlayerNavigationDialog() = default;

    BOOL Create(CWnd* pParent = nullptr);

    // Dialog Data
    enum { IDD = IDD_NAVIGATION_DLG };

    void UpdateElementList();
    void UpdatePos(int nID);
    void ResetTabs();

    void SetChannelInfoAvailable(bool bAvailable);
    CTabCtrl m_tabSelChannelList;

protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    virtual BOOL OnInitDialog();

    DECLARE_MESSAGE_MAP()

    afx_msg void OnDestroy();
    afx_msg void OnChangeChannel();
    afx_msg void OnTunerScan();
    afx_msg void OnShowChannelInfo();
    afx_msg void OnUpdateShowChannelInfoButton(CCmdUI* pCmdUI);
    afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
    afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
};
