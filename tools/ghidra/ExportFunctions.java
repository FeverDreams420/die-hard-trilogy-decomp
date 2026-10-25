// Writes one TSV row per function: address, size, instruction count, call count,
// name source and name. Prints only a one-line summary to the console.
// Usage (headless): -postScript ExportFunctions.java <output.tsv>
// @category DieHard

import java.io.PrintWriter;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.symbol.SourceType;

public class ExportFunctions extends GhidraScript {
	@Override
	protected void run() throws Exception {
		String out = getScriptArgs()[0];
		int total = 0, named = 0, leaves = 0;
		try (PrintWriter w = new PrintWriter(out)) {
			w.println("addr\tsize\tinsns\tcalls\tsource\tname");
			for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
				int insns = 0, calls = 0;
				InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
				while (it.hasNext()) {
					Instruction i = it.next();
					insns++;
					if (i.getFlowType().isCall()) {
						calls++;
					}
				}
				SourceType src = f.getSymbol().getSource();
				w.printf("0x%s\t0x%X\t%d\t%d\t%s\t%s%n", f.getEntryPoint(), f.getBody().getNumAddresses(),
					insns, calls, src, f.getName());
				total++;
				if (src != SourceType.DEFAULT) {
					named++;
				}
				if (calls == 0) {
					leaves++;
				}
			}
		}
		println(String.format("SUMMARY %s: %d functions, %d named, %d leaves -> %s",
			currentProgram.getName(), total, named, leaves, out));
	}
}
