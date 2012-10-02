
#ifndef ovView_h
#define ovView_h

#include <QObject>

#include <QStringList>

#include <vector>

class vtkContextView;
class vtkTable;

class ovView : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QString name READ name)
  Q_PROPERTY(QStringList attributes READ attributes)
public:
  ovView(QObject *parent);
  ~ovView();

  virtual void setTable(vtkTable *data, vtkContextView *view) = 0;
  virtual QString name() = 0;
  virtual QStringList attributes() { return QStringList(); }
  virtual void prepareForRender() { }

public slots:
  virtual QStringList attributeOptions(QString attribute) { return QStringList(); }
  virtual void setAttribute(QString attribute, QString value) { }
  virtual QString getAttribute(QString attribute) { return QString(); }

protected:
};

#endif
