#!/usr/bin/env python3
import sys
import statistics
import collections
from operator import itemgetter
import requests
from requests.auth import HTTPBasicAuth
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import QTimer, QTime, QDate, QDateTime
import urllib3

class getRequest():
    def __init__(self, url):
        self.username = "RO"
        self.url = url

    def unit(self):
        self.password = "just4reading"
        try:
            result = requests.get(
                url=self.url,
                auth=HTTPBasicAuth(self.username, self.password),
                verify=False)
            if result:
                return result
            f = open('error.log', 'w')
            f.write(result.text)
            f.close()
        except requests.exceptions.RequestException as e:
            f = open('error.log', 'w')
            f.write(str(e))
            f.close()
        sys.exit()

    def stat(self):
        self.password = "Passw0rd"
        try:
            result = requests.get(
                url=self.url,
                auth=HTTPBasicAuth(self.username, self.password),
                verify=False)
            if result:
                return result
            f = open('error.log', 'w')
            f.write(result.text)
            f.close()
        except requests.exceptions.RequestException as e:
            f = open('error.log', 'w')
            f.write(str(e))
            f.close()
        sys.exit()


class get():
    def repeatedVisitors(self, startDate, endDate):
        siteId = getRequest('https://cisco-presence.unit.ua/api/config/v1/sites').stat().json()[0]['aesUidString']
        ret = getRequest('https://cisco-presence.unit.ua/api/presence/v1/repeatvisitors/count?siteId=' + siteId +
                         '&startDate=' + startDate + '&endDate=' + endDate).stat().json()
        res = collections.OrderedDict({'First Time': ret['FIRST_TIME'], 'Daily': ret['DAILY'], 'Weekly': ret['WEEKLY'],
                                       'Occasional': ret['OCCASIONAL']})
        return res

    def dwellTime(self, startDate, endDate):
        siteId = getRequest('https://cisco-presence.unit.ua/api/config/v1/sites').stat().json()[0]['aesUidString']
        ret = getRequest('https://cisco-presence.unit.ua/api/presence/v1/dwell/count?siteId=' + siteId +
                         '&startDate=' + startDate + '&endDate=' + endDate).stat().json()
        res = collections.OrderedDict(
            {'5-30 minutes': ret['FIVE_TO_THIRTY_MINUTES'], '30-60 minutes': ret['THIRTY_TO_SIXTY_MINUTES'],
             '1-5 hours': ret['ONE_TO_FIVE_HOURS'], '5-8 hours': ret['FIVE_TO_EIGHT_HOURS'],
             'more than 8 hours': ret['EIGHT_PLUS_HOURS']})
        return res

    def correlation(self):
        siteId = getRequest('https://cisco-presence.unit.ua/api/config/v1/sites').stat().json()[0]['aesUidString']
        ret = getRequest('https://cisco-presence.unit.ua/api/presence/v1/connected/daily?siteId=' + siteId +
                         '&startDate=2017-12-22&endDate=' + QDate().currentDate().addDays(-1).toString(
            'yyyy-MM-dd')).stat().json()
        week = [[], [], [], [], [], [], []]
        index = 4
        for key in ret:
            week[index].append(ret[key])
            index += 1
            if index > 6:
                index = 0
        new_week = collections.OrderedDict()
        names = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday']
        for i, day in enumerate(week):
            new_week[names[i]] = int(statistics.median(day))
        return new_week

    def forecasting(self):
        siteId = getRequest('https://cisco-presence.unit.ua/api/config/v1/sites').stat().json()[0]['aesUidString']
        start = QDateTime(QDate(2017, 12, 21)).toTime_t()
        past = QDate().currentDate().addDays(-6)
        tomorrow = collections.OrderedDict({'5-30 minutes': [], '30-60 minutes': [], '1-5 hours': [], '5-8 hours': [],
                                            'more than 8 hours': []})
        while QDateTime(past).toTime_t() > start:
            ret = getRequest('https://cisco-presence.unit.ua/api/presence/v1/dwell/count?siteId=' + siteId + '&date=' +
                             past.toString('yyyy-MM-dd')).stat().json()
            tomorrow['5-30 minutes'].append(ret['FIVE_TO_THIRTY_MINUTES'])
            tomorrow['30-60 minutes'].append(ret['THIRTY_TO_SIXTY_MINUTES'])
            tomorrow['1-5 hours'].append(ret['ONE_TO_FIVE_HOURS'])
            tomorrow['5-8 hours'].append(ret['FIVE_TO_EIGHT_HOURS'])
            tomorrow['more than 8 hours'].append(ret['EIGHT_PLUS_HOURS'])
            past = past.addDays(-7)
        tomorrow['5-30 minutes'] = int(statistics.median(tomorrow['5-30 minutes']))
        tomorrow['30-60 minutes'] = int(statistics.median(tomorrow['30-60 minutes']))
        tomorrow['1-5 hours'] = int(statistics.median(tomorrow['1-5 hours']))
        tomorrow['5-8 hours'] = int(statistics.median(tomorrow['5-8 hours']))
        tomorrow['more than 8 hours'] = int(statistics.median(tomorrow['more than 8 hours']))
        return tomorrow

    def floors(self):
        array = getRequest("https://cisco-cmx.unit.ua/api/config/v1/maps/floor/list").unit().json()
        array = [elem.split('>') for elem in array]
        campus = set()
        for elem in array:
            campus.add(elem[0])
        new = {}
        for elem in campus:
            new[elem] = set(building[1] for building in array if building[0] == elem)
        campus = {}
        for key in new:
            campus[key] = {}
            for val in new[key]:
                campus[key][val] = [floor[2] for floor in array if floor[0] == key and floor[1] == val]
        return campus

    def floorImg(self, campus, building, floor):
        return getRequest("https://cisco-cmx.unit.ua/api/config/v1/maps/image/" +
                          campus + "/" + building + "/" + floor).unit().content

    def users(self, campus, building, floor):
        result = getRequest("https://cisco-cmx.unit.ua/api/location/v2/clients").unit().json()
        floorId = getRequest("https://cisco-cmx.unit.ua/api/config/v1/maps/info/" +
                             campus + "/" + building + "/" + floor).unit().json()["aesUidString"]
        result = [elem for elem in result if elem['mapInfo']['floorRefId'] == floorId]
        for item in result:
            if item['ipAddress'] is not None:
                if len(item['ipAddress']) == 2:
                    item['ipAddress'] = str(item['ipAddress'][0]) + "\n" + str(item['ipAddress'][1])
                else:
                    item['ipAddress'] = str(item['ipAddress'][0])
            else:
                item['ipAddress'] = ''
            if item['mapCoordinate'] is not None:
                item['pos'] = {}
                item['pos']['x'] = item['mapCoordinate']['x']
                item['pos']['y'] = item['mapCoordinate']['y']
                item['mapCoordinate'] = 'X: ' + str(item['mapCoordinate']['x']) + "\n" + 'Y: ' + str(
                    item['mapCoordinate']['y'])
            else:
                item['pos'] = None
                item['mapCoordinate'] = ''
            if item['manufacturer'] is None:
                item['manufacturer'] = ''
        return result

    def allUsers(self):
        return getRequest("https://cisco-cmx.unit.ua/api/location/v2/clients").unit().json()


class Ui_Ccmn(object):
    def setupUi(self, Ccmn):
        Ccmn.resize(1280, 720)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(Ccmn.sizePolicy().hasHeightForWidth())
        Ccmn.setSizePolicy(sizePolicy)
        self.CcmnLayout = QtWidgets.QHBoxLayout(Ccmn)
        self.CcmnLayout.setContentsMargins(0, 0, 0, 0)
        self.CcmnLayout.setSpacing(0)
        self.tabWidget = QtWidgets.QTabWidget(Ccmn)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.tabWidget.sizePolicy().hasHeightForWidth())
        self.tabWidget.setSizePolicy(sizePolicy)
        self.tabWidget.setStyleSheet("QTabWidget::tab-bar{ alignment:middle;}")
        self.MapTab = QtWidgets.QWidget()
        self.MapTabLayout = QtWidgets.QHBoxLayout(self.MapTab)
        self.MapTabLayout.setContentsMargins(2, 0, 0, 0)
        self.MapTabLayout.setSpacing(2)
        self.NotificationFloorsShowButton = QtWidgets.QPushButton(self.MapTab)
        self.NotificationFloorsShowButton.setEnabled(True)
        self.NotificationFloorsShowButton.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.NotificationFloorsShowButton.setAutoFillBackground(False)
        self.NotificationFloorsShowButton.setStyleSheet("border:none;")
        self.MapTabLayout.addWidget(self.NotificationFloorsShowButton)
        self.MainSplitter = QtWidgets.QSplitter(self.MapTab)
        self.MainSplitter.setMinimumSize(QtCore.QSize(519, 0))
        self.MainSplitter.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.MainSplitter.setOrientation(QtCore.Qt.Horizontal)
        self.MainSplitter.setChildrenCollapsible(False)
        self.NotificationFloorsTabWidget = QtWidgets.QTabWidget(self.MainSplitter)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(1)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.NotificationFloorsTabWidget.sizePolicy().hasHeightForWidth())
        self.NotificationFloorsTabWidget.setSizePolicy(sizePolicy)
        self.NotificationFloorsTabWidget.setMinimumSize(QtCore.QSize(250, 0))
        self.NotificationFloorsTabWidget.setStyleSheet("QTabWidget::tab-bar{ alignment: left;}")
        self.NotificationTab = QtWidgets.QWidget()
        self.NotificationTab.setStyleSheet("")
        self.NotificationTabLayout = QtWidgets.QHBoxLayout(self.NotificationTab)
        self.NotificationTabLayout.setContentsMargins(0, 0, 0, 0)
        self.NotificationTabLayout.setSpacing(0)
        self.NotificationListScrollArea = QtWidgets.QScrollArea(self.NotificationTab)
        self.NotificationListScrollArea.setStyleSheet("")
        self.NotificationListScrollArea.setWidgetResizable(True)
        self.NotificationListWidget = QtWidgets.QWidget()
        self.NotificationListWidget.setGeometry(QtCore.QRect(0, 0, 225, 660))
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Maximum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.NotificationListWidget.sizePolicy().hasHeightForWidth())
        self.NotificationListWidget.setSizePolicy(sizePolicy)
        self.NotificationListWidgetLayout = QtWidgets.QVBoxLayout(self.NotificationListWidget)
        self.NotificationListWidgetLayout.setContentsMargins(4, 4, 4, 4)
        self.NotificationListWidgetLayout.setSpacing(4)
        self.NotificationListScrollArea.setWidget(self.NotificationListWidget)
        self.NotificationTabLayout.addWidget(self.NotificationListScrollArea)
        self.NotificationHideButton = QtWidgets.QPushButton(self.NotificationTab)
        self.NotificationHideButton.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.NotificationHideButton.setAutoFillBackground(False)
        self.NotificationHideButton.setStyleSheet("border:none")
        self.NotificationTabLayout.addWidget(self.NotificationHideButton)
        self.NotificationFloorsTabWidget.addTab(self.NotificationTab, "")
        self.FloorTab = QtWidgets.QWidget()
        self.FloorTabLayout = QtWidgets.QHBoxLayout(self.FloorTab)
        self.FloorTabLayout.setContentsMargins(0, 0, 0, 0)
        self.FloorTabLayout.setSpacing(0)
        self.FloorsListScrollArea = QtWidgets.QScrollArea(self.FloorTab)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.FloorsListScrollArea.sizePolicy().hasHeightForWidth())
        self.FloorsListScrollArea.setSizePolicy(sizePolicy)
        self.FloorsListScrollArea.setWidgetResizable(True)
        self.FloorListWidget = QtWidgets.QWidget()
        self.FloorListWidget.setGeometry(QtCore.QRect(0, 0, 225, 16))
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Maximum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.FloorListWidget.sizePolicy().hasHeightForWidth())
        self.FloorListWidget.setSizePolicy(sizePolicy)
        self.FloorListWidgetLayout = QtWidgets.QVBoxLayout(self.FloorListWidget)
        self.FloorListWidgetLayout.setContentsMargins(0, 0, 0, 0)
        self.FloorListWidgetLayout.setSpacing(0)
        self.FloorsListScrollArea.setWidget(self.FloorListWidget)
        self.FloorTabLayout.addWidget(self.FloorsListScrollArea)
        self.FloorsHideButton = QtWidgets.QPushButton(self.FloorTab)
        self.FloorsHideButton.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.FloorsHideButton.setAutoFillBackground(False)
        self.FloorsHideButton.setStyleSheet("border:none;")
        self.FloorTabLayout.addWidget(self.FloorsHideButton)
        self.NotificationFloorsTabWidget.addTab(self.FloorTab, "")
        self.CenterQsplitter = QtWidgets.QSplitter(self.MainSplitter)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(15)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.CenterQsplitter.sizePolicy().hasHeightForWidth())
        self.CenterQsplitter.setSizePolicy(sizePolicy)
        self.CenterQsplitter.setOrientation(QtCore.Qt.Vertical)
        self.CenterQsplitter.setChildrenCollapsible(False)
        self.MapScrollArea = QtWidgets.QScrollArea(self.CenterQsplitter)
        self.MapScrollArea.setEnabled(True)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(100)
        sizePolicy.setVerticalStretch(100)
        sizePolicy.setHeightForWidth(self.MapScrollArea.sizePolicy().hasHeightForWidth())
        self.MapScrollArea.setSizePolicy(sizePolicy)
        self.MapScrollArea.setMinimumSize(QtCore.QSize(0, 30))
        self.MapScrollArea.setWidgetResizable(True)
        self.MapScrollAreaWidget = QtWidgets.QWidget()
        self.MapScrollAreaWidget.setGeometry(QtCore.QRect(0, 0, 787, 460))
        self.MapScrollAreaWidgetLayout = QtWidgets.QHBoxLayout(self.MapScrollAreaWidget)
        self.MapScrollAreaWidgetLayout.setContentsMargins(0, 0, 0, 0)
        self.MapScrollAreaWidgetLayout.setSpacing(0)
        self.MapScrollArea.setWidget(self.MapScrollAreaWidget)
        self.ConnectedUsersBox = QtWidgets.QWidget(self.CenterQsplitter)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(100)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.ConnectedUsersBox.sizePolicy().hasHeightForWidth())
        self.ConnectedUsersBox.setSizePolicy(sizePolicy)
        self.ConnectedUsersBoxLayout = QtWidgets.QVBoxLayout(self.ConnectedUsersBox)
        self.ConnectedUsersBoxLayout.setContentsMargins(0, 0, 0, 0)
        self.ConnectedUsersBoxLayout.setSpacing(4)
        self.HideMapLayout = QtWidgets.QHBoxLayout()
        self.HideMapLayout.setSizeConstraint(QtWidgets.QLayout.SetMinimumSize)
        self.HideMapLayout.setSpacing(0)
        spacerItem = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.HideMapLayout.addItem(spacerItem)
        self.MapShowButton = QtWidgets.QPushButton(self.ConnectedUsersBox)
        self.MapShowButton.setEnabled(True)
        self.MapShowButton.setMinimumSize(QtCore.QSize(0, 0))
        self.MapShowButton.setMaximumSize(QtCore.QSize(20, 20))
        self.MapShowButton.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.MapShowButton.setAutoFillBackground(False)
        self.MapShowButton.setStyleSheet("border:none;")
        self.HideMapLayout.addWidget(self.MapShowButton)
        self.MapHideButton = QtWidgets.QPushButton(self.ConnectedUsersBox)
        self.MapHideButton.setMaximumSize(QtCore.QSize(30, 20))
        self.MapHideButton.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.MapHideButton.setAutoFillBackground(False)
        self.MapHideButton.setStyleSheet("border:none;")
        self.HideMapLayout.addWidget(self.MapHideButton)
        self.HideMapLayout.addItem(
            QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum))
        self.SearchButton = QtWidgets.QPushButton(self.ConnectedUsersBox)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.SearchButton.sizePolicy().hasHeightForWidth())
        self.SearchButton.setSizePolicy(sizePolicy)
        self.SearchButton.setMaximumSize(QtCore.QSize(20, 20))
        self.SearchButton.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.SearchButton.setAutoFillBackground(False)
        self.SearchButton.setStyleSheet("border:none;")
        self.HideMapLayout.addWidget(self.SearchButton)
        self.ConnectedUsersBoxLayout.addLayout(self.HideMapLayout)
        self.SearchFrame = QtWidgets.QFrame(self.ConnectedUsersBox)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.SearchFrame.sizePolicy().hasHeightForWidth())
        self.SearchFrame.setSizePolicy(sizePolicy)
        self.SearchFrame.setStyleSheet("QFrame{border:none;}")
        self.SearchFrame.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.SearchFrame.setFrameShadow(QtWidgets.QFrame.Raised)
        self.SearchFrameLayout = QtWidgets.QHBoxLayout(self.SearchFrame)
        self.SearchFrameLayout.setContentsMargins(0, 0, 0, 0)
        self.SearchFrameLayout.setSpacing(10)
        self.SearchField = QtWidgets.QLineEdit(self.SearchFrame)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.SearchField.sizePolicy().hasHeightForWidth())
        self.SearchField.setSizePolicy(sizePolicy)
        self.SearchField.setMinimumSize(QtCore.QSize(0, 0))
        self.SearchField.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.SearchField.setStyleSheet("margin:0;")
        self.SearchField.setText("")
        self.SearchFrameLayout.addWidget(self.SearchField)
        self.SearchBarCloseButton = QtWidgets.QPushButton(self.SearchFrame)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.SearchBarCloseButton.sizePolicy().hasHeightForWidth())
        self.SearchBarCloseButton.setSizePolicy(sizePolicy)
        self.SearchBarCloseButton.setMaximumSize(QtCore.QSize(20, 20))
        font = QtGui.QFont()
        font.setPointSize(7)
        self.SearchBarCloseButton.setFont(font)
        self.SearchFrameLayout.addWidget(self.SearchBarCloseButton)
        self.ConnectedUsersBoxLayout.addWidget(self.SearchFrame)
        self.ConnectedUsersScrollArea = QtWidgets.QScrollArea(self.ConnectedUsersBox)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(100)
        sizePolicy.setVerticalStretch(100)
        sizePolicy.setHeightForWidth(self.ConnectedUsersScrollArea.sizePolicy().hasHeightForWidth())
        self.ConnectedUsersScrollArea.setSizePolicy(sizePolicy)
        self.ConnectedUsersScrollArea.setMinimumSize(QtCore.QSize(300, 100))
        self.ConnectedUsersScrollArea.setWidgetResizable(True)
        self.ConnectedUsersWidget = QtWidgets.QWidget()
        self.ConnectedUsersWidget.setGeometry(QtCore.QRect(0, 0, 787, 16))
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Maximum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.ConnectedUsersWidget.sizePolicy().hasHeightForWidth())
        self.ConnectedUsersWidget.setSizePolicy(sizePolicy)
        self.ConnectedUsersWidgetLayout = QtWidgets.QVBoxLayout(self.ConnectedUsersWidget)
        self.ConnectedUsersWidgetLayout.setContentsMargins(4, 4, 4, 4)
        self.ConnectedUsersWidgetLayout.setSpacing(10)
        self.ConnectedUsersScrollArea.setWidget(self.ConnectedUsersWidget)
        self.ConnectedUsersBoxLayout.addWidget(self.ConnectedUsersScrollArea)
        self.UserInfoBox = QtWidgets.QWidget(self.MainSplitter)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(1)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.UserInfoBox.sizePolicy().hasHeightForWidth())
        self.UserInfoBox.setSizePolicy(sizePolicy)
        self.UserInfoBoxLayout = QtWidgets.QVBoxLayout(self.UserInfoBox)
        self.UserInfoBoxLayout.setContentsMargins(0, 0, 0, 0)
        self.UserInfoBoxLayout.setSpacing(3)
        self.UserInfoLayout = QtWidgets.QHBoxLayout()
        self.UserInfoLayout.setSpacing(5)
        self.UserInfoLabel = QtWidgets.QLabel(self.UserInfoBox)
        self.UserInfoLabel.setAlignment(QtCore.Qt.AlignLeading | QtCore.Qt.AlignLeft | QtCore.Qt.AlignTop)
        self.UserInfoLayout.addWidget(self.UserInfoLabel)
        spacerItem2 = QtWidgets.QSpacerItem(40, 15, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.UserInfoLayout.addItem(spacerItem2)
        self.UserInfoCloseButton = QtWidgets.QPushButton(self.UserInfoBox)
        self.UserInfoCloseButton.setMaximumSize(QtCore.QSize(20, 20))
        font = QtGui.QFont()
        font.setPointSize(7)
        self.UserInfoCloseButton.setFont(font)
        self.UserInfoLayout.addWidget(self.UserInfoCloseButton)
        self.UserInfoBoxLayout.addLayout(self.UserInfoLayout)
        self.UserInfoScrollArea = QtWidgets.QScrollArea(self.UserInfoBox)
        self.UserInfoScrollArea.setMinimumSize(QtCore.QSize(200, 0))
        self.UserInfoScrollArea.setWidgetResizable(True)
        self.UserInfoWidget = QtWidgets.QWidget()
        self.UserInfoWidget.setGeometry(QtCore.QRect(0, 0, 198, 16))
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Ignored, QtWidgets.QSizePolicy.Maximum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.UserInfoWidget.sizePolicy().hasHeightForWidth())
        self.UserInfoWidget.setSizePolicy(sizePolicy)
        self.UserInfoWidgetLayout = QtWidgets.QVBoxLayout(self.UserInfoWidget)
        self.UserInfoWidgetLayout.setContentsMargins(0, 0, 0, 0)
        self.UserInfoWidgetLayout.setSpacing(0)
        self.UserInfoScrollArea.setWidget(self.UserInfoWidget)
        self.UserInfoBoxLayout.addWidget(self.UserInfoScrollArea)
        self.MapTabLayout.addWidget(self.MainSplitter)
        self.tabWidget.addTab(self.MapTab, "")
        self.statisticTab = QtWidgets.QWidget()
        self.StatisticTabLayout = QtWidgets.QGridLayout(self.statisticTab)
        self.StatisticTabLayout.setContentsMargins(0, 0, 0, 0)
        self.StatisticTabLayout.setSpacing(0)
        self.dateWidget = QtWidgets.QWidget(self.statisticTab)
        self.dateWidgetLayout = QtWidgets.QHBoxLayout(self.dateWidget)
        self.dateWidgetLayout.setContentsMargins(0, 0, 0, 0)
        self.dateWidgetLayout.setSpacing(0)
        self.dateWidgetLayout.addItem(
            QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum))
        self.dateEditFrom = QtWidgets.QDateEdit(self.dateWidget)
        self.dateEditFrom.setMinimumDate(QtCore.QDate(2017, 12, 21))
        self.dateEditFrom.setMaximumDate(QtCore.QDate().currentDate())
        self.dateEditFrom.setCalendarPopup(True)
        self.dateWidgetLayout.addWidget(self.dateEditFrom)
        self.dateEditTo = QtWidgets.QDateEdit(self.dateWidget)
        self.dateEditTo.setMinimumDate(QtCore.QDate(2017, 12, 21))
        self.dateEditTo.setMaximumDate(QtCore.QDate().currentDate())
        self.dateEditTo.setCalendarPopup(True)
        self.dateEditTo.setDate(QtCore.QDate().currentDate())
        self.dateWidgetLayout.addWidget(self.dateEditTo)
        self.dateWidgetLayout.addItem(
            QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum))
        self.StatisticTabLayout.addWidget(self.dateWidget, 0, 0, 1, 2)
        self.AnalyticsBox = QtWidgets.QGroupBox(self.statisticTab)
        self.AnalyticsLayout = QtWidgets.QHBoxLayout(self.AnalyticsBox)
        self.AnalyticsGraphics = QtWidgets.QGraphicsView(self.AnalyticsBox)
        self.AnalyticsGraphics.setMinimumSize(QtCore.QSize(0, 301))
        self.AnalyticsLayout.addWidget(self.AnalyticsGraphics)
        self.StatisticTabLayout.addWidget(self.AnalyticsBox, 1, 0, 1, 1)
        self.PresenceBox = QtWidgets.QGroupBox(self.statisticTab)
        self.PresenceLayout = QtWidgets.QHBoxLayout(self.PresenceBox)
        self.PresenceGraphics = QtWidgets.QGraphicsView(self.PresenceBox)
        self.PresenceGraphics.setMinimumSize(QtCore.QSize(0, 301))
        self.PresenceLayout.addWidget(self.PresenceGraphics)
        self.StatisticTabLayout.addWidget(self.PresenceBox, 1, 1, 1, 1)
        self.ForecastingBox = QtWidgets.QGroupBox(self.statisticTab)
        self.ForecastingLayout = QtWidgets.QHBoxLayout(self.ForecastingBox)
        self.ForecastingGraphics = QtWidgets.QGraphicsView(self.ForecastingBox)
        self.ForecastingGraphics.setMinimumSize(QtCore.QSize(0, 301))
        self.ForecastingLayout.addWidget(self.ForecastingGraphics)
        self.StatisticTabLayout.addWidget(self.ForecastingBox, 3, 1, 1, 1)
        self.CorrelationBox = QtWidgets.QGroupBox(self.statisticTab)
        self.CorrelationLayout = QtWidgets.QHBoxLayout(self.CorrelationBox)
        self.CorrelationGraphics = QtWidgets.QGraphicsView(self.CorrelationBox)
        self.CorrelationGraphics.setMinimumSize(QtCore.QSize(0, 301))
        self.CorrelationLayout.addWidget(self.CorrelationGraphics)
        self.StatisticTabLayout.addWidget(self.CorrelationBox, 3, 0, 1, 1)
        self.tabWidget.addTab(self.statisticTab, "")
        self.CcmnLayout.addWidget(self.tabWidget)

        self.translate = QtCore.QCoreApplication.translate
        self.retranslateUi(Ccmn)
        self.tabWidget.setCurrentIndex(0)
        self.NotificationFloorsTabWidget.setCurrentIndex(1)
        self.NotificationHideButton.clicked.connect(self.NotificationFloorsTabWidget.hide)
        self.FloorsHideButton.clicked.connect(self.NotificationFloorsTabWidget.hide)
        self.NotificationFloorsShowButton.clicked.connect(self.NotificationFloorsTabWidget.show)
        self.NotificationFloorsShowButton.clicked.connect(self.NotificationFloorsShowButton.hide)
        self.NotificationHideButton.clicked.connect(self.NotificationFloorsShowButton.show)
        self.MapShowButton.clicked.connect(self.MapHideButton.show)
        self.MapHideButton.clicked.connect(self.MapHideButton.hide)
        self.MapShowButton.clicked.connect(self.MapShowButton.hide)
        self.MapShowButton.clicked.connect(self.MapScrollArea.show)
        self.MapHideButton.clicked.connect(self.MapShowButton.show)
        self.FloorsHideButton.clicked.connect(self.NotificationFloorsShowButton.show)
        self.SearchBarCloseButton.clicked.connect(self.SearchButton.show)
        self.SearchButton.clicked.connect(self.SearchFrame.show)
        self.SearchButton.clicked.connect(self.SearchButton.hide)
        self.MapHideButton.clicked.connect(self.MapScrollArea.hide)
        self.dateEditFrom.dateChanged['QDate'].connect(lambda: (
            self.dateEditTo.setMinimumDate(self.dateEditFrom.date()),
            self.loadStatistic(0)
        ))
        self.dateEditTo.dateChanged['QDate'].connect(lambda: self.loadStatistic(0))
        QtCore.QMetaObject.connectSlotsByName(Ccmn)

        self.SearchFrame.hide()
        self.UserInfoBox.hide()
        self.NFTWW = self.NotificationFloorsTabWidget.width()
        self.MapShowButton.hide()
        self.NotificationFloorsShowButton.hide()
        self.SearchBarCloseButton.clicked.connect(lambda: (self.SearchField.setText(""), self.SearchFrame.hide()))
        self.UserInfoCloseButton.clicked.connect(
            lambda: (self.UserInfoBox.hide(), QTimer().singleShot(100, self.strechTabs)))
        self.NotificationFloorsShowButton.clicked.connect(lambda: QTimer().singleShot(100, self.strechTabs))
        self.MainSplitter.splitterMoved['int', 'int'].connect(self.strechTabs)
        Ccmn.resizeEvent = lambda event: QTimer().singleShot(100, self.strechTabs)
        QtCore.QMetaObject.connectSlotsByName(Ccmn)
        self.client = collections.OrderedDict({'macAddress': 'MAC Address:', 'dot11Status': 'Status:',
                                               'ipAddress': 'IP Address:', 'mapCoordinate': 'Co-ordinates:',
                                               'manufacturer': 'Manufacturer:',
                                               'apMacAddress': 'Connected AP:',
                                               'detectingControllers': 'Detecting Controllers:', 'ssId': 'SSID:',
                                               'userName': 'User Name:', 'band': 'Band:', 'bytesSent': 'Bytes Sent:',
                                               'bytesReceived': 'Bytes Received:'})
        self.userInfo = {}
        j = 0
        for i in self.client:
            self.userInfo[j] = QtWidgets.QLabel(self.UserInfoWidget)
            self.userInfo[j].setStyleSheet(
                "background-color: white; border:1px solid; border-bottom: none; font-weight: bold; color: #27a;")
            self.userInfo[j].setWordWrap(True)
            self.UserInfoWidgetLayout.addWidget(self.userInfo[j])
            self.userInfo[j].setText(self.translate('Ccmn', self.client[i]))
            j += 1
            self.userInfo[j] = QtWidgets.QLabel(self.UserInfoWidget)
            self.userInfo[j].setStyleSheet(
                "background-color: white; border: 1px solid; border-top: none; margin-bottom: 5px;padding:5px 0;")
            self.userInfo[j].setAlignment(QtCore.Qt.AlignLeading | QtCore.Qt.AlignLeft | QtCore.Qt.AlignTop)
            self.userInfo[j].setWordWrap(True)
            self.UserInfoWidgetLayout.addWidget(self.userInfo[j])
            j += 1
        self.loadFloors()
        self.SearchField.textChanged['QString'].connect(self.filter)
        self.label = []
        self.users = 0
        self.notifications()
        self.loadStatistic(1)

    def loadStatistic(self, flag):
        self.text = []
        self.nbr = []
        self.scene = []
        repeated = get().repeatedVisitors(self.dateEditFrom.date().toString('yyyy-MM-dd'),
                                        self.dateEditTo.date().toString('yyyy-MM-dd'))
        dwell = get().dwellTime(self.dateEditFrom.date().toString('yyyy-MM-dd'),
                              self.dateEditTo.date().toString('yyyy-MM-dd'))
        if flag:
            self.correlation = get().correlation()
            self.forecasting = get().forecasting()
        data = [[self.AnalyticsGraphics, repeated], [self.PresenceGraphics, dwell],
                [self.CorrelationGraphics, self.correlation], [self.ForecastingGraphics, self.forecasting]]
        colours = []
        palette = [0x24A14D, 0xEB9E3E, 0xCE3B3E, 0x3576BE, 0x389FD3, 0x9548A9, 0x008080]
        for i in palette:
            colours.append(QtGui.QColor(i))

        for item in data:
            start_angle = 0
            count = 0
            total = sum([item[1][x] for x in item[1]])
            y = 10
            self.scene.append(QtWidgets.QGraphicsScene())
            self.scene[-1].setSceneRect(0, 0, 470, 300)
            for elem in item[1]:
                angle = round(float(item[1][elem] * 5760) / total)
                ellipse = QtWidgets.QGraphicsEllipseItem(0, 0, 300, 300)
                ellipse.setPos(0, 0)
                ellipse.setStartAngle(start_angle)
                ellipse.setSpanAngle(angle)
                ellipse.setPen(QtGui.QColor(0xffffff))
                ellipse.setBrush(colours[count])
                start_angle += angle
                self.scene[-1].addRect(350, y, 40, 15, QtGui.QPen(QtGui.QColor(0xFFFFFF)),
                                       QtGui.QBrush(QtGui.QColor(palette[count])))
                self.text.append(QtWidgets.QGraphicsTextItem())
                self.nbr.append(QtWidgets.QGraphicsTextItem())
                self.text[-1].setPos(347, y + 15)
                self.text[-1].setPlainText(elem)
                self.nbr[-1].setPos(390, y - 3)
                self.nbr[-1].setPlainText(str(item[1][elem]))
                count += 1
                y += 40
                self.scene[-1].addItem(self.text[-1])
                self.scene[-1].addItem(self.nbr[-1])
                self.scene[-1].addItem(ellipse)

            item[0].setScene(self.scene[-1])

    def notifications(self):
        users = get().allUsers()
        if self.users is 0:
            self.label.append(QtWidgets.QLabel(self.NotificationListWidget))
            self.label[-1].setStyleSheet("background-color:white;border:1px solid;text-align: left;padding: 5px 2px;")
            self.label[-1].setWordWrap(True)
            self.label[-1].setText(
                self.translate('Ccmn', QTime.currentTime().toString() + '\nTotal: ' + str(len(users))))
            self.NotificationListWidgetLayout.addWidget(self.label[-1])
            self.users = [{'mac': elem['macAddress'], 'location': elem['mapInfo']['mapHierarchyString'].split('>')[2]}
                          for elem in users]
        else:
            newUsers = [{'mac': elem['macAddress'], 'location': elem['mapInfo']['mapHierarchyString'].split('>')[2]} for
                        elem in users]
            diff = [elem for elem in newUsers if elem not in self.users]
            if len(diff) > 0:
                for user in diff:
                    self.label.append(QtWidgets.QLabel(self.NotificationListWidget))
                    self.label[-1].setStyleSheet(
                        "background-color:white;border:1px solid;text-align: left;padding: 5px 2px;")
                    self.label[-1].setWordWrap(True)
                    self.label[-1].setText(self.translate('Ccmn',
                                                          QTime.currentTime().toString() + '\n' + 'New user on the ' +
                                                          user['location'] + ':\n' + user['mac'] + '\nTotal: ' + str(
                                                              len(users))))
                    self.NotificationListWidgetLayout.addWidget(self.label[-1])
                self.users = newUsers
                QTimer().singleShot(100, lambda: self.NotificationListScrollArea.verticalScrollBar().setSliderPosition(
                    self.NotificationListScrollArea.verticalScrollBar().maximum()))
        QTimer().singleShot(5000, self.notifications)

    def filter(self):
        for i in range(self.ConnectedUsersWidgetLayout.count()):
            self.ConnectedUsersWidgetLayout.itemAt(i).widget().hide()
            if self.SearchField.text() in self.ConnectedUsersWidgetLayout.itemAt(i).widget().text():
                self.ConnectedUsersWidgetLayout.itemAt(i).widget().show()

    def strechTabs(self):
        self.NFTWW = self.MainSplitter.sizes()[0]
        self.NotificationFloorsTabWidget.tabBar().setMinimumWidth(self.NFTWW)

    def loadFloors(self):
        self.Floors = QtWidgets.QToolBox(self.FloorListWidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Maximum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.Floors.sizePolicy().hasHeightForWidth())
        self.Floors.setSizePolicy(sizePolicy)
        self.Floors.layout().setSpacing(0)
        self.floor = {}
        array = get().floors()
        for campus in sorted(array):
            self.floor[campus] = QtWidgets.QWidget()
            sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Maximum)
            sizePolicy.setHorizontalStretch(0)
            sizePolicy.setVerticalStretch(0)
            sizePolicy.setHeightForWidth(self.floor[campus].sizePolicy().hasHeightForWidth())
            self.floor[campus].setSizePolicy(sizePolicy)
            self.floor[str(campus) + 'layout'] = QtWidgets.QVBoxLayout(self.floor[campus])
            self.floor[str(campus) + 'layout'].setContentsMargins(0, 0, 0, 0)
            self.floor[str(campus) + 'layout'].setSpacing(0)
            self.floor[str(campus) + 'buildings'] = QtWidgets.QToolBox(self.floor[campus])
            sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Maximum)
            sizePolicy.setHorizontalStretch(0)
            sizePolicy.setVerticalStretch(0)
            sizePolicy.setHeightForWidth(self.floor[str(campus) + 'buildings'].sizePolicy().hasHeightForWidth())
            self.floor[str(campus) + 'buildings'].setSizePolicy(sizePolicy)
            self.floor[str(campus) + 'buildings'].layout().setSpacing(0)

            for building in sorted(array[campus]):
                self.floor[str(campus) + str(building)] = QtWidgets.QWidget()
                sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Maximum)
                sizePolicy.setHorizontalStretch(0)
                sizePolicy.setVerticalStretch(0)
                sizePolicy.setHeightForWidth(self.floor[str(campus) + str(building)].sizePolicy().hasHeightForWidth())
                self.floor[str(campus) + str(building)].setSizePolicy(sizePolicy)
                self.floor[str(campus) + str(building) + 'layout'] = QtWidgets.QVBoxLayout(
                    self.floor[str(campus) + str(building)])
                self.floor[str(campus) + str(building) + 'layout'].setContentsMargins(0, 0, 0, 0)
                self.floor[str(campus) + str(building) + 'layout'].setSpacing(0)
                for floor in sorted(array[campus][building]):
                    self.floor[str(campus) + str(building) + str(floor)] = QtWidgets.QPushButton(
                        self.floor[str(campus) + str(building)])
                    self.floor[str(campus) + str(building) + 'layout'].addWidget(
                        self.floor[str(campus) + str(building) + str(floor)])
                    self.floor[str(campus) + str(building) + str(floor)].setText(self.translate("Ccmn", str(floor)))
                    self.floor[str(campus) + str(building) + str(floor)].clicked.connect(
                        self.loadImg(campus, building, floor))

                self.floor[str(campus) + 'buildings'].addItem(self.floor[str(campus) + str(building)], '')
                self.floor[str(campus) + 'buildings'].setItemText(
                    self.floor[str(campus) + 'buildings'].indexOf(self.floor[str(campus) + str(building)]),
                    self.translate("Ccmn", str(building)))

            self.floor[str(campus) + 'layout'].addWidget(self.floor[str(campus) + 'buildings'])
            self.Floors.addItem(self.floor[campus], '')
            self.Floors.setItemText(self.Floors.indexOf(self.floor[campus]), self.translate("Ccmn", str(campus)))

        self.FloorListWidgetLayout.addWidget(self.Floors)

    def loadImg(self, campus, building, floor):
        def f():
            data = get().floorImg(campus, building, floor)
            self.image = QtGui.QImage()
            self.image.loadFromData(data)
            self.pos = None
            delete = self.MapScrollAreaWidgetLayout.takeAt(0)
            if delete is not None:
                delete.widget().deleteLater()
            self.widget = QtWidgets.QWidget(self.MapScrollAreaWidget)
            self.widget.setMinimumSize(QtCore.QSize(self.image.width(), self.image.height()))
            self.lbl = QtWidgets.QLabel(self.widget)
            self.lbl.setGeometry(QtCore.QRect(0, 0, self.image.width(), self.image.height()))
            self.lbl.setPixmap(QtGui.QPixmap(self.image))
            self.MapScrollAreaWidgetLayout.addWidget(self.widget)
            self.loadUsers(campus, building, floor)

        return f

    def loadUsers(self, campus, building, floor):
        users = get().users(campus, building, floor)
        self.user = {}
        for i in reversed(range(self.ConnectedUsersWidgetLayout.count())):
            self.ConnectedUsersWidgetLayout.itemAt(i).widget().deleteLater()
        for i, user in enumerate(sorted(users, key=itemgetter('manufacturer'))):
            self.user[i] = QtWidgets.QPushButton(self.ConnectedUsersWidget)
            self.user[i].setCursor(QtGui.QCursor(QtCore.Qt.PointingHandCursor))
            self.user[i].setFlat(True)
            self.user[i].setStyleSheet("background-color:white;border:1px solid;text-align:left;padding: 5px 2px;")
            self.ConnectedUsersWidgetLayout.addWidget(self.user[i])
            if user['manufacturer'] is not '':
                self.user[i].setText(self.translate('Ccmn', 'macAddress: ' + user['macAddress'] +
                                                    ', manufacturer: ' + user['manufacturer']))
            else:
                self.user[i].setText(self.translate('Ccmn', 'macAddress: ' + user['macAddress']))
            self.user[i].clicked.connect(self.loadUser(user))
        QTimer().singleShot(10, self.filter)

    def loadUser(self, user):
        def f():
            self.UserInfoBox.show()
            QTimer().singleShot(100, self.strechTabs)
            if user['pos'] is not None:
                if self.pos is None:
                    self.MapScrollAreaWidgetLayout.takeAt(0).widget().deleteLater()
                    self.widget = QtWidgets.QWidget(self.MapScrollAreaWidget)
                    self.widget.setMinimumSize(QtCore.QSize(self.image.width(), self.image.height()))
                    self.lbl = QtWidgets.QLabel(self.widget)
                    self.lbl.setGeometry(QtCore.QRect(0, 0, self.image.width(), self.image.height()))
                    self.lbl.setPixmap(QtGui.QPixmap(self.image))
                    self.MapScrollAreaWidgetLayout.addWidget(self.widget)
                    self.pos = QtWidgets.QRadioButton(self.widget)
                    self.pos.setMaximumSize(QtCore.QSize(20, 20))
                    self.pos.setStyleSheet(
                        "QRadioButton::indicator::unchecked { border:3px solid;border-radius:10px;background-color:#ff0;position:absolute;}")
                    self.pos.setCheckable(False)
                    self.pos.raise_()
                self.pos.setGeometry(QtCore.QRect(user['pos']['x'], user['pos']['y'], 20, 20))
                self.MapScrollAreaWidgetLayout.addWidget(self.widget)
                QTimer().singleShot(10, self.moveScroll(user))
            j = 1
            for i in self.client:
                self.userInfo[j].setText(self.translate('Ccmn', str(user[i])))
                j += 2

        return f

    def moveScroll(self, user):
        def f():
            x = self.MainSplitter.sizes()[1]
            y = self.CenterQsplitter.sizes()[0]
            if y is not 0:
                self.MapScrollArea.ensureVisible(user['pos']['x'], user['pos']['y'], int(x / 2), int(y / 2))

        return f

    def retranslateUi(self, Ccmn):
        Ccmn.setWindowTitle(self.translate("Ccmn", "CCMN"))
        self.NotificationFloorsShowButton.setText(self.translate("Ccmn", "⏩ "))
        self.NotificationHideButton.setText(self.translate("Ccmn", "⏪ "))
        self.NotificationFloorsTabWidget.setTabText(self.NotificationFloorsTabWidget.indexOf(self.NotificationTab),
                                                    self.translate("Ccmn", "Notifications"))
        self.FloorsHideButton.setText(self.translate("Ccmn", "⏪ "))
        self.NotificationFloorsTabWidget.setTabText(self.NotificationFloorsTabWidget.indexOf(self.FloorTab),
                                                    self.translate("Ccmn", "Floors"))
        self.MapShowButton.setText(self.translate("Ccmn", "⏬ "))
        self.MapHideButton.setText(self.translate("Ccmn", "  ⏫ "))
        self.SearchButton.setText(self.translate("Ccmn", "🔍 "))
        self.SearchBarCloseButton.setText(self.translate("Ccmn", "❌"))
        self.UserInfoLabel.setText(self.translate("Ccmn", "User Info"))
        self.UserInfoCloseButton.setText(self.translate("Ccmn", "❌"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.MapTab), self.translate("Ccmn", "Map"))
        self.dateEditFrom.setDisplayFormat(self.translate("Ccmn", "dd.MM.yyyy"))
        self.dateEditTo.setDisplayFormat(self.translate("Ccmn", "dd.MM.yyyy"))
        self.AnalyticsBox.setTitle(self.translate("Ccmn", "Analytics (Repeat Visitors)"))
        self.PresenceBox.setTitle(self.translate("Ccmn", "Presence (Connected Visitors Dwell Time)"))
        self.ForecastingBox.setTitle(self.translate("Ccmn", "Forecasting (Tomorrow)"))
        self.CorrelationBox.setTitle(self.translate("Ccmn", "Correlation (Connected Visitors And Day)"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.statisticTab), self.translate("Ccmn", "Statistic"))


if __name__ == "__main__":
    urllib3.disable_warnings()
    app = QtWidgets.QApplication(sys.argv)
    Ccmn = QtWidgets.QWidget()
    ui = Ui_Ccmn()
    ui.setupUi(Ccmn)
    Ccmn.show()
    sys.exit(app.exec_())
