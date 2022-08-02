#include "echoeditor.h"
#include "echoeditor_p.h"
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QtGlobal>

namespace dspace {

EchoEditor::EchoEditor(QWidget *parent)
    : QWidget(parent), d_ptr(new EchoEditorPrivate(this)) {}

EchoEditor::~EchoEditor() {}

const QString EchoEditor::pluginName() const { return QString("echo-editor"); }
const QString EchoEditor::pluginDisplayName() const {
  return QString("Echo Editor");
}

QWidget *EchoEditor::pluginWidget(const QString &key) {
  Q_UNUSED(key)
  QGroupBox *box = new QGroupBox();
  box->setGeometry(0, 0, 100, 50);
  Q_D(EchoEditor);
  d->m_lineEdit->setParent(box);
  d->m_lineEdit->setText(d->m_buffer);
  d->m_label->setParent(box);
  d->m_label->setText(d->m_buffer);
  d->m_button->setParent(box);
  d->m_lineEdit->setGeometry(0, 0, 75, 25);
  d->m_lineEdit->setGeometry(75, 0, 25, 25);
  d->m_label->setGeometry(0, 25, 100, 25);
  connect(d->m_button, &QPushButton::clicked, [=](bool checked) {
    Q_UNUSED(checked)
    d->m_buffer = d->m_lineEdit->text();
    d->m_label->setText(d->m_buffer);
  });
  return box;
}

EchoEditorPrivate::EchoEditorPrivate(EchoEditor *q) : q_ptr(q) {
  m_lineEdit = new QLineEdit();
  m_label = new QLabel();
  m_button = new QPushButton("保存");
}

EchoEditorPrivate::~EchoEditorPrivate() {
  delete m_lineEdit;
  delete m_label;
}

} // namespace dspace