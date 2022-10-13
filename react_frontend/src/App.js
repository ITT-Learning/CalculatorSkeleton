import { useState } from 'react';

import apiService from './services/apiService.js';

import CalcInput from './Components/CalcInput.jsx';
import CalcResult from './Components/CalcResult.jsx';
import VariableInput from './Components/VariableInput.jsx';

import './App.css';

function App() 
{
    const [calcValue , setCalcValue ] = useState("");
    const [isValid   , setIsValid   ] = useState(false);
    const [variables , setVariables ] = useState({});
    const [calcResult, setCalcResult] = useState("");



    const doInputChange = ({ currentTarget: target }) =>
    {
        const sanitizedInput = target.value
            .split(/[^\w+\-*/\(\)]|_/) // regex to select only things that are neither alphanumeric (including _) nor +-*/(), and then also select underscores
            .filter(i => i != "")
            .map(i => i.toLowerCase())
            .join("");
        setCalcValue(sanitizedInput);

        if (target.value.length <= 0)
        {
            setIsValid(false);
            setCalcResult("");
            setVariables({});
            setTitle("Calculator")
            return;
        }
        
        const variableNames = extractVariableNames(sanitizedInput);
        const uVariables    = combineVariablesUsing(variableNames);
        setVariables(uVariables);

        doApiCall(sanitizedInput, uVariables);
    };
    
    
    
    const doVariableChange = ({ currentTarget: target }) =>
    {
        const uVariables = {...variables};
        const newValue = target.value.split(/\D/).join("");
        uVariables[target.name].value = newValue.length > 0 ? newValue : null;
        setVariables(uVariables);
        doApiCall(calcValue, uVariables);
    };
    
    
    
    const doApiCall = (equation, p_variables) =>
    {
        const variableValues = getVariableValues(p_variables);
        const req = {equation, variables: variableValues};
        
        apiService.post("calculate/no-history", JSON.stringify(req))
        .then ((res) => {
            console.log("result: ", res.data);
            setCalcResult(+res.data);
            setTitle(res.data);
            setIsValid(true);
        })
        .catch ((error) => {
            console.log(error.response.data);
            setCalcResult(error.response.data);
            setIsValid(false);
            setTitle("Error");
        });
    };



    const setTitle = (title) =>
    {
        document.getElementsByTagName("title")[0].innerText = title;
    };



    const objToArray = (obj) =>
    {
        const outArray = [];
        for (let key in obj)
        {
            const newItem = {...obj[key]};
            newItem.key   = key;
            outArray.push(newItem);
        }
        return outArray;
    };



    const extractVariableNames = (equation) =>
    {
        const variableNames = {};
        const namesList = equation
            .split(/[\W\d]+/)
            .filter(n => n != "")
            .map(n => n.toLowerCase())
            .sort();
        for (let index in namesList)
        {
            variableNames[namesList[index]] = {value: null};
        }
        return variableNames;
    };



    const combineVariablesUsing = (variableNames) =>
    {
        const uVariables = {};
        for (let name in variableNames)
        {
            uVariables[name] = variables[name] ? variables[name] : variableNames[name];
        }
        return uVariables;
    };



    const getVariableValues = (variables) =>
    {
        const variableValues = [];
        for (let name in variables)
        {
            const value = variables[name].value;
            if (value)
            {
                variableValues.push( {name, value: +value} );
            }
        }
        return variableValues;
    };



    return (
        <div className="bg-dark d-flex flex-column flex-grow-1">
            <CalcResult value={calcResult} isValid={isValid} />
            <CalcInput value={calcValue} handleChange={doInputChange} />
            <div className="d-flex mt-3 flex-grow-1">
                <div className="position-relative flex-grow-1 overflow-y">
                    <div className="d-flex flex-column px-3 position-absolute h-100 w-100">
                    {
                        objToArray(variables).map((variable) =>
                        <VariableInput key={variable.key} name={variable.key} value={variable.value} handleChange={doVariableChange} />
                        )
                    }
                    </div>
                </div>
                <div className="position-relative flex-grow-1">
                    <div className="d-flex flex-column px-3 overflow-y position-absolute h-100 w-100">
                        {/* TODO add history here */}
                    </div>
                </div>
            </div>
        </div>
    );
}

export default App;
