package expo.modules.updates.logging

import android.util.Log

class UpdatesLogger {

    fun trace(
        message: String,
        code: UpdatesErrorCode
    ) {
        trace(message, code, null, null)
    }

    fun trace(
        message: String,
        code: UpdatesErrorCode,
        updateId: String?,
        assetId: String?
    ) {
        log(message, code, UpdatesLogType.Trace, updateId, assetId)
    }

    fun debug(
        message: String,
        code: UpdatesErrorCode
    ) {
        debug(message, code, null, null)
    }

    fun debug(
        message: String,
        code: UpdatesErrorCode,
        updateId: String?,
        assetId: String?
    ) {
        log(message, code, UpdatesLogType.Debug, updateId, assetId)
    }

    fun info(
        message: String,
        code: UpdatesErrorCode
    ) {
        info(message, code, null, null)
    }

    fun info(
        message: String,
        code: UpdatesErrorCode,
        updateId: String?,
        assetId: String?
    ) {
        log(message, code, UpdatesLogType.Info, updateId, assetId)
    }

    fun warn(
        message: String,
        code: UpdatesErrorCode
    ) {
        warn(message, code, null, null)
    }

    fun warn(
        message: String,
        code: UpdatesErrorCode,
        updateId: String?,
        assetId: String?
    ) {
        log(message, code, UpdatesLogType.Warn, updateId, assetId)
    }

    fun error(
        message: String,
        code: UpdatesErrorCode
    ) {
        error(message, code, null, null)
    }

    fun error(
        message: String,
        code: UpdatesErrorCode,
        updateId: String?,
        assetId: String?
    ) {
        log(message, code, UpdatesLogType.Error, updateId, assetId)
    }

    fun fatal(
        message: String,
        code: UpdatesErrorCode
    ) {
        fatal(message, code, null, null)
    }

    fun fatal(
        message: String,
        code: UpdatesErrorCode,
        updateId: String?,
        assetId: String?
    ) {
        log(message, code, UpdatesLogType.Fatal, updateId, assetId)
    }


    private fun log(
        message: String,
        code: UpdatesErrorCode,
        level: UpdatesLogType,
        updateId: String?,
        assetId: String?
    ) {
        val logEntry = UpdatesLogEntry(0, message, UpdatesErrorCode.asString(code), UpdatesLogType.asString(level), updateId, assetId, null)
        when (UpdatesLogType.toOSLogType(level)) {
            Log.DEBUG -> Log.d(TAG, logEntry.asString())
            Log.INFO -> Log.i(TAG, logEntry.asString())
            Log.WARN -> Log.w(TAG, logEntry.asString())
            Log.ERROR -> Log.e(TAG, logEntry.asString())
            Log.ASSERT -> Log.e(TAG, logEntry.asString())
        }
    }

    companion object {
        const val TAG = "expo-updates"
    }
}