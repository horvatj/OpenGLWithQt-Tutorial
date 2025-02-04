/************************************************************************************

OpenGL with Qt - Tutorial
-------------------------
Autor      : Andreas Nicolai <andreas.nicolai@gmx.net>
Repository : https://github.com/ghorwin/OpenGLWithQt-Tutorial
License    : BSD License,
			 see https://github.com/ghorwin/OpenGLWithQt-Tutorial/blob/master/LICENSE

************************************************************************************/

#include "TestDialog.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "RectangleWindow.h"

TestDialog::TestDialog() :
#ifdef Q_OS_WIN
	QDialog(nullptr, Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint)
#else
	QDialog(nullptr, Qt::Window)
#endif
{
	// *** create OpenGL window

	QSurfaceFormat format;
	format.setRenderableType(QSurfaceFormat::OpenGL);
	format.setProfile(QSurfaceFormat::CoreProfile);
	format.setVersion(3,3);

	m_rectangleWindow = new RectangleWindow;
	m_rectangleWindow->setFormat(format);

	// *** create window container widget

	QWidget *container = QWidget::createWindowContainer(m_rectangleWindow);
    container->setMinimumSize(QSize(1024, 768));

	// *** create the layout and insert widget container

    QVBoxLayout * vlay = new QVBoxLayout;
    vlay->setMargin(0);
    vlay->setSpacing(0);
    vlay->addWidget(container);

//	// now create some buttons at the bottom

//	QHBoxLayout * hlay = new QHBoxLayout;
//	hlay->setMargin(0);

//	QPushButton * changeColorBtn = new QPushButton(tr("Change colors"), this);
//	connect(changeColorBtn, &QPushButton::clicked, this, &TestDialog::onChangeColors);

//	QPushButton * changeColorAnimationBtn = new QPushButton(tr("Animate colors"), this);
//	connect(changeColorAnimationBtn, &QPushButton::clicked, this, &TestDialog::onAnimateColors);

//	QPushButton * closeBtn = new QPushButton(tr("Close"), this);
//	connect(closeBtn, &QPushButton::clicked, this, &QDialog::accept);

//	hlay->addWidget(changeColorBtn);
//	hlay->addWidget(changeColorAnimationBtn);
//	hlay->addStretch();
//	hlay->addWidget(closeBtn);

//	vlay->addLayout(hlay);

	setLayout(vlay);

	qsrand(428); // for now use fixed seed so that we get the same colors every time
}
