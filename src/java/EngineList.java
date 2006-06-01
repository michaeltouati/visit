// ****************************************************************************
//
// Copyright (c) 2000 - 2006, The Regents of the University of California
// Produced at the Lawrence Livermore National Laboratory
// All rights reserved.
//
// This file is part of VisIt. For details, see http://www.llnl.gov/visit/. The
// full copyright notice is contained in the file COPYRIGHT located at the root
// of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
//
// Redistribution  and  use  in  source  and  binary  forms,  with  or  without
// modification, are permitted provided that the following conditions are met:
//
//  - Redistributions of  source code must  retain the above  copyright notice,
//    this list of conditions and the disclaimer below.
//  - Redistributions in binary form must reproduce the above copyright notice,
//    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
//    documentation and/or materials provided with the distribution.
//  - Neither the name of the UC/LLNL nor  the names of its contributors may be
//    used to  endorse or  promote products derived from  this software without
//    specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
// ARE  DISCLAIMED.  IN  NO  EVENT  SHALL  THE  REGENTS  OF  THE  UNIVERSITY OF
// CALIFORNIA, THE U.S.  DEPARTMENT  OF  ENERGY OR CONTRIBUTORS BE  LIABLE  FOR
// ANY  DIRECT,  INDIRECT,  INCIDENTAL,  SPECIAL,  EXEMPLARY,  OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
// SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
// CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
// LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
// OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
// DAMAGE.
//
// ****************************************************************************

package llnl.visit;

import java.util.Vector;
import java.lang.Integer;

// ****************************************************************************
// Class: EngineList
//
// Purpose:
//    This class contains a list of host names on which engines are running.
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   Tue Mar 30 17:34:14 PST 2004
//
// Modifications:
//   
// ****************************************************************************

public class EngineList extends AttributeSubject
{
    public EngineList()
    {
        super(5);

        engines = new Vector();
        numProcessors = new Vector();
        numNodes = new Vector();
        loadBalancing = new Vector();
        simulationName = new Vector();
    }

    public EngineList(EngineList obj)
    {
        super(5);

        int i;

        engines = new Vector(obj.engines.size());
        for(i = 0; i < obj.engines.size(); ++i)
            engines.addElement(new String((String)obj.engines.elementAt(i)));

        numProcessors = new Vector();
        for(i = 0; i < obj.numProcessors.size(); ++i)
        {
            Integer iv = (Integer)obj.numProcessors.elementAt(i);
            numProcessors.addElement(new Integer(iv.intValue()));
        }
        numNodes = new Vector();
        for(i = 0; i < obj.numNodes.size(); ++i)
        {
            Integer iv = (Integer)obj.numNodes.elementAt(i);
            numNodes.addElement(new Integer(iv.intValue()));
        }
        loadBalancing = new Vector();
        for(i = 0; i < obj.loadBalancing.size(); ++i)
        {
            Integer iv = (Integer)obj.loadBalancing.elementAt(i);
            loadBalancing.addElement(new Integer(iv.intValue()));
        }
        simulationName = new Vector(obj.simulationName.size());
        for(i = 0; i < obj.simulationName.size(); ++i)
            simulationName.addElement(new String((String)obj.simulationName.elementAt(i)));


        SelectAll();
    }

    public boolean equals(EngineList obj)
    {
        int i;

        // Create the return value
        return ((engines == obj.engines) &&
                (numProcessors == obj.numProcessors) &&
                (numNodes == obj.numNodes) &&
                (loadBalancing == obj.loadBalancing) &&
                (simulationName == obj.simulationName));
    }

    // Property setting methods
    public void SetEngines(Vector engines_)
    {
        engines = engines_;
        Select(0);
    }

    public void SetNumProcessors(Vector numProcessors_)
    {
        numProcessors = numProcessors_;
        Select(1);
    }

    public void SetNumNodes(Vector numNodes_)
    {
        numNodes = numNodes_;
        Select(2);
    }

    public void SetLoadBalancing(Vector loadBalancing_)
    {
        loadBalancing = loadBalancing_;
        Select(3);
    }

    public void SetSimulationName(Vector simulationName_)
    {
        simulationName = simulationName_;
        Select(4);
    }

    // Property getting methods
    public Vector GetEngines() { return engines; }
    public Vector GetNumProcessors() { return numProcessors; }
    public Vector GetNumNodes() { return numNodes; }
    public Vector GetLoadBalancing() { return loadBalancing; }
    public Vector GetSimulationName() { return simulationName; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteStringVector(engines);
        if(WriteSelect(1, buf))
            buf.WriteIntVector(numProcessors);
        if(WriteSelect(2, buf))
            buf.WriteIntVector(numNodes);
        if(WriteSelect(3, buf))
            buf.WriteIntVector(loadBalancing);
        if(WriteSelect(4, buf))
            buf.WriteStringVector(simulationName);
    }

    public void ReadAtts(int n, CommunicationBuffer buf)
    {
        for(int i = 0; i < n; ++i)
        {
            int index = (int)buf.ReadByte();
            switch(index)
            {
            case 0:
                SetEngines(buf.ReadStringVector());
                break;
            case 1:
                SetNumProcessors(buf.ReadIntVector());
                break;
            case 2:
                SetNumNodes(buf.ReadIntVector());
                break;
            case 3:
                SetLoadBalancing(buf.ReadIntVector());
                break;
            case 4:
                SetSimulationName(buf.ReadStringVector());
                break;
            }
        }
    }


    // Attributes
    private Vector engines; // vector of String objects
    private Vector numProcessors; // vector of Integer objects
    private Vector numNodes; // vector of Integer objects
    private Vector loadBalancing; // vector of Integer objects
    private Vector simulationName; // vector of String objects
}

