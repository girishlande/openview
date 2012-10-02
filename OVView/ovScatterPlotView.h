
#ifndef ovScatterPlotView_h
#define ovScatterPlotView_h

#include "ovView.h"
#include "vtkNew.h"
#include "vtkSmartPointer.h"

class vtkChartXY;
class vtkContextView;
class vtkTable;

class ovScatterPlotView : public ovView
{
  Q_OBJECT
public:
  ovScatterPlotView(QObject *parent);
  ~ovScatterPlotView();

  virtual void setTable(vtkTable *data, vtkContextView *view);
  virtual QString name();

  virtual QStringList attributes();
  virtual QStringList attributeOptions(QString attribute);
  virtual void setAttribute(QString attribute, QString value);
  virtual QString getAttribute(QString attribute);

protected:
  void generatePlot();
  int tableColumnIndex(QString value);

  int m_x;
  int m_y;
  vtkSmartPointer<vtkTable> m_table;
  vtkNew<vtkChartXY> m_chart;
};

#endif
