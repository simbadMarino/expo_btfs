package abi46_0_0.expo.modules.storereview

import android.content.Context
import abi46_0_0.expo.modules.core.BasePackage

class StoreReviewPackage : BasePackage() {
  override fun createExportedModules(context: Context) = listOf(StoreReviewModule(context))
}
