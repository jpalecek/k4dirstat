#pragma once
/*
 *   License:	LGPL - See file COPYING.LIB for details.
 *   Author:	Stefan Hundhammer <sh@suse.de>
 *              Joshua Hodosh <kdirstat@grumpypenguin.org>
 */

#include "kcleanup.h"

// Forward declarations
class KActionCollection;

namespace KDirStat {
/**
 * Predefined standard @ref KCleanup actions to be performed on
 * @ref KDirTree items.
 *
 * This class is not meant to be ever instantiated - use the static methods
 * only.
 *
 * For details about what each individual method does, refer to the help
 * file. Use the old (KDirStat 0.86) help file in case the current help
 * file isn't available yet.
 *
 * @short KDirStat standard cleanup actions
 **/

class KStdCleanup {
public:
  static KCleanup *openInKonqueror(QString &icon, QKeySequence &shortcut);
  static KCleanup *openInTerminal(QString &icon, QKeySequence &shortcut);
  static KCleanup *compressSubtree(QString &icon, QKeySequence &shortcut);
  static KCleanup *makeClean(QString &icon, QKeySequence &shortcut);
  static KCleanup *deleteTrash(QString &icon, QKeySequence &shortcut);
  static KCleanup *moveToTrashBin(QString &icon, QKeySequence &shortcut);
  static KCleanup *hardDelete(QString &icon, QKeySequence &shortcut);

private:
  /**
   * Prevent instances of this class - private constructor / destructor.
   **/
  KStdCleanup() {}
  ~KStdCleanup() {}
};

class TrashBinCleanup : public KCleanup {
public:
  TrashBinCleanup();
public slots:
  void execute(KDirTree * tree) override;
};

} // namespace KDirStat

