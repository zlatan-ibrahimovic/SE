package stree;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

import stree.*;
import type.Temp;


public class StreePROCEDURE extends Stree {

	public StreePROCEDURE(Stree left,Stree right){
		super(EnumTag.PROCEDURE,left,right,"main");
    }

	@Override
	public Temp getTemp() {
		// TODO Auto-generated method stub
		return null;
	}


    
}
