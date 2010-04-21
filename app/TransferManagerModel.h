#ifndef TRANSFERMANAGERMODEL_H
#define TRANSFERMANAGERMODEL_H

#include <QAbstractTableModel>
#include <QXmppTransferManager.h>

class TransferManagerModel : public QAbstractTableModel
{
Q_OBJECT
public:
    enum ColumnName
    {
        Jid       = 0,
        FileName  = 1,
        Process   = 2,
        FileSize  = 3,
        State     = 4,
        Method    = 5,
        Direction = 6
    };
    explicit TransferManagerModel(QObject *parent = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

signals:

public slots:
    void addJobToList(QXmppTransferJob *job);
    void removeJobFromList(QXmppTransferJob *job);

private:
    //QXmppTransferManager *m_transferManager;
    QList<QXmppTransferJob *> m_jobList;
};

#endif // TRANSFERMANAGERMODEL_H
