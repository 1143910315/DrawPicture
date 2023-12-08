#ifndef SIMILARITYFILTERING_H
#define SIMILARITYFILTERING_H

#include <QThread>

class SimilarityFiltering : public QThread
{
    Q_OBJECT
public:
    SimilarityFiltering();
};

#endif // SIMILARITYFILTERING_H
