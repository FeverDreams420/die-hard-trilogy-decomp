// Prints program options (all categories) whose name contains the given text.
// Usage (headless): -postScript PrintOptions.java <filter>
// @category DieHard

import ghidra.app.script.GhidraScript;
import ghidra.framework.options.Options;

public class PrintOptions extends GhidraScript {
	@Override
	protected void run() throws Exception {
		String filter = getScriptArgs()[0].toLowerCase();
		for (String cat : currentProgram.getOptionsNames()) {
			Options opts = currentProgram.getOptions(cat);
			for (String name : opts.getOptionNames()) {
				if ((cat + "." + name).toLowerCase().contains(filter)) {
					println("OPTION " + cat + "." + name + " = " + opts.getObject(name, null));
				}
			}
		}
	}
}
