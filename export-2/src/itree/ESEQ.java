package itree;

import type.*;

public class ESEQ extends Exp {
	public ITree stm;
	public ITree exp;
	

	public ESEQ(ITree stm, ITree exp) {
		super();
		this.stm = stm;
		this.exp = exp;
		
	}


	public String toString() {
		return "ESEQ";
	}

	public void toDot(StringBuffer str) {
		str.append("e_" + id + " [");
		str.append("shape=\"ellipse\", label=\"" + toString());
		str.append("\"];\n");
		
		if (stm != null) {
			stm.toDot(str);
			str.append("e_" + id + " -> e_" + stm.id + ";\n");
		}
		if(exp!=null){
			exp.toDot(str);
			str.append("e_" + id + " -> e_" + exp.id + ";\n");
		}
	}


}
