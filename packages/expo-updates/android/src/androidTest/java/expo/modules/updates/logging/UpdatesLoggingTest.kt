package expo.modules.updates

import expo.modules.updates.logging.UpdatesLogEntry
import junit.framework.TestCase
import org.junit.Assert
import org.junit.Test

class UpdatesLoggingTest: TestCase() {

    @Test
    fun testLogEntryConversion() {
        val entry = UpdatesLogEntry(12345678, "Test message", "NoUpdatesAvailable", "error", null, null, null)
        val json = entry.asString()
        val entryCopy = UpdatesLogEntry.create(json)
        Assert.assertEquals(entry.message, entryCopy.message)
        Assert.assertEquals(entry.timestamp, entryCopy.timestamp)
        Assert.assertEquals(entry.code, entryCopy.code)
        Assert.assertEquals(entry.level, entryCopy.level)
        Assert.assertNull(entryCopy.updateId)
        Assert.assertNull(entryCopy.assetId)
        Assert.assertNull(entryCopy.stacktrace)
    }

    @Test
    fun testLogEntryConversion2() {
        val entry = UpdatesLogEntry(12345678, "Test message", "UpdateFailedToLoad", "fatal", "myUpdateId", "myAssetId", listOf("stack frame 1", "stack frame 2"))
        val json = entry.asString()
        val entryCopy = UpdatesLogEntry.create(json)
        Assert.assertEquals(entry.message, entryCopy.message)
        Assert.assertEquals(entry.timestamp, entryCopy.timestamp)
        Assert.assertEquals(entry.code, entryCopy.code)
        Assert.assertEquals(entry.level, entryCopy.level)
        Assert.assertEquals(entry.updateId, entryCopy.updateId)
        Assert.assertEquals(entry.assetId, entryCopy.assetId)
        Assert.assertNotNull(entryCopy.stacktrace)
        Assert.assertEquals(entry.stacktrace?.size, entryCopy.stacktrace?.size)
    }

}