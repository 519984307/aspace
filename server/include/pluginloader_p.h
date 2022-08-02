#pragma once
#include "pluginloader.h"
#include <QString>
#include <qlist.h>
namespace dspace {
class PluginLoaderPrivate {
public:
    explicit PluginLoaderPrivate(PluginLoader *q);
    ~PluginLoaderPrivate();

protected:
    bool loadPlugins();

private:
    Q_DECLARE_PUBLIC(PluginLoader)
    PluginLoader                    *q_ptr;
    QStringList                     m_pluginDirs;
    QList<PluginInterface *>        m_plugins;
};


}