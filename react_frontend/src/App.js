import { useState } from 'react';

import apiService from './services/apiService.js';

import CalcInput from './Components/CalcInput.jsx';
import CalcResult from './Components/CalcResult.jsx';
import VariableInput from './Components/VariableInput.jsx';

import './App.css';

function App() 
{
    const [calcValue,  setCalcValue]  = useState("");
    const [error,      setError]      = useState("");
    const [variables,  setVariables]  = useState({});
    const [calcResult, setCalcResult] = useState(null);



    const doInputChange = ({ currentTarget: target }) =>
    {
        // regex to select only things that aren't alphanumeric (including _) or +-*/(), and then also select underscores
        const sanitizedInput = target.value.split(/[^\w+\-*/\(\)]|_/).filter(i => i != "").join("");
        setCalcValue(sanitizedInput);

        if (target.value.length <= 0)
        {
            setError("");
            setCalcResult("");
            setVariables({});
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
            setError("");
        })
        .catch ((error) => {
            console.log(error.response.data);
            setCalcResult(null);
            setError(error.response.data);
        });
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
        const namesList = equation.split(/[\W\d]+/).filter(n => n != "").sort();
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
        <div className="bg-dark h-100 d-flex flex-column">
            <CalcInput value={calcValue} handleChange={doInputChange} error={error} />
            <CalcResult value={calcResult} />
            <div className="">
            {
                objToArray(variables).map((variable) =>
                <VariableInput key={variable.key} name={variable.key} value={variable.value} handleChange={doVariableChange} />
                )
            }
            </div>
        </div>
    );
}

export default App;
