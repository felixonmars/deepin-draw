/*
 *  Copyright (C) 2020 ~ 2021 Uniontech Software Technology Co.,Ltd.
 *
 * Author:     Zhang Hao <zhanghao@uniontech.com>
 *
 * Maintainer: WangYu <wangyu@uniontech.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <QTimer>
#include <QtConcurrent/QtConcurrent>

#include "dialog.h"
#include "publicApi.h"
#include "application.h"
#include "mainwindow.h"
#include "ccentralwidget.h"
#include "cgraphicsview.h"

TEST(isFileNameLegal, ins1)
{
    ASSERT_EQ(false, drawApp->isFileNameLegal("/sadhgasdjhasdg/sahdkjahskdjhaskd"));
}

TEST(isFileNameLegal, ins2)
{
    ASSERT_EQ(false, drawApp->isFileNameLegal("./"));
}

TEST(isFileNameLegal, ins3)
{
    ASSERT_EQ(true, drawApp->isFileNameLegal("./myfile.txt"));
}

TEST(isFileNameLegal, ins4)
{
    ASSERT_EQ(false, drawApp->isFileNameLegal(""));
}

//TEST(isFileNameLegal, ins5)
//{
//    QTimer::singleShot(1000, drawApp->topMainWindowWidget(), [ = ]() {
//        auto dial = qobject_cast<Dialog *>(qApp->activeModalWidget());
//        if (dial != nullptr) {
//            dial->done(1);
//        }
//    });
//    getMainWindow()->close();
//}

//TEST(getRightFiles, ins0)
//{
//    auto currentPath = QApplication::applicationDirPath();
//    QStringList testPaths{ currentPath + "/test_cut.ddf", currentPath + "/oldBlurItem.ddf",
//                           ":/test.ddf", currentPath + "/test.png", ""};
//    auto result = drawApp->getRightFiles(testPaths, true);
//    ASSERT_TRUE(testPaths != result);

//    QEventLoop loop;
//    QtConcurrent::run([ =, &loop]() {
//        (void)QTest::qWaitFor([ =, &loop]() {
//            return (loop.isRunning());
//        });

//        (void)QTest::qWaitFor([ = ]() {
//            return (qApp->activeModalWidget() != nullptr && qApp->activeModalWidget() != getMainWindow());
//        });
//        if (qApp->activeModalWidget() != nullptr) {
//            QThread::msleep(200);
//            DDialog *dialog = qobject_cast<DDialog *>(qApp->activeModalWidget());
//            QMetaObject::invokeMethod(dialog, "done", Q_ARG(int, 1));

//            QThread::msleep(200);
//            QMetaObject::invokeMethod(&loop, "quit");
//        } else {
//            QMetaObject::invokeMethod(&loop, "quit");
//        }
//    });
//    loop.exec();
//}

TEST(isFileExist, ins0)
{
    QString testPath("asy8!@#$%^&*()hhr8o37hrf9ehl");
    ASSERT_EQ(drawApp->isFileExist(testPath), false);
}

TEST(isFileExist, ins1)
{
    QString testPath("/etc/profile");
    ASSERT_EQ(drawApp->isFileExist(testPath), true);
}

TEST(isFileExist, ins2)
{
    QString testPath("file:///etc/profile");
    ASSERT_EQ(drawApp->isFileExist(testPath), true);
    ASSERT_EQ(testPath, QString("/etc/profile"));
}

TEST(isFileExist, ins3)
{
    QString testPath("file:///etc/asy8!@#$%^&*()hhr8o37hrf9ehl");
    ASSERT_EQ(drawApp->isFileExist(testPath), false);
}

TEST(application, otherfunction)
{
    //补充application类的测试
    getMainWindow()->topLevelWidget();
    drawApp->activateWindow();
    drawApp->onAttributionChanged(1, 1, 1, true);
    drawApp->systemThemeColor();
    drawApp->currenDefaultAttriVar(1);
}
