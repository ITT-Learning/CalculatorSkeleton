import { useEffect, useState } from 'react';

import apiService from './services/apiService.js';

import CalcInput from './Components/CalcInput.jsx';
import CalcResult from './Components/CalcResult.jsx';
import VariableInput from './Components/VariableInput.jsx';
import HistoryEntry from './Components/HistoryEntry.jsx';

import './App.css';

function App() 
{
    const [calcValue , setCalcValue ] = useState("");
    const [isValid   , setIsValid   ] = useState(false);
    const [variables , setVariables ] = useState({});
    const [calcResult, setCalcResult] = useState("");
    const [history   , setHistory   ] = useState([]);



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

        doApiCall(sanitizedInput, uVariables, false);
    };
    
    
    
    const doVariableChange = ({ currentTarget: target }) =>
    {
        const uVariables = {...variables};
        const newValue = target.value.split(/\D/).join("");
        uVariables[target.name].value = newValue.length > 0 ? newValue : null;
        setVariables(uVariables);
        doApiCall(calcValue, uVariables, false);
    };
    
    
    
    const doApiCall = (equation, p_variables, history) =>
    {
        const variableValues = getVariableValues(p_variables);
        const req = {equation, variables: variableValues};

        const endpoint = "calculate" + (history ? "" : "/no-history");
        apiService.post(endpoint, JSON.stringify(req))
        .then ((res) => {
            console.log("result: ", res.data);
            setCalcResult(+res.data);
            setTitle(res.data);
            setIsValid(true);
            if (history)
            {
                getHistory();
            }
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



    const getHistory = () =>
    {
        apiService.get("history")
            .then( res => { setHistory(res.data) } )
            .catch( error => { console.error("Unable to get history:", error); } )
    };
    // NOTE use effect here to be called after initialization of getHistory
    useEffect(getHistory, []);



    const doSaveHistory = () =>
    {
        doApiCall(calcValue, variables, true)
    };



    const doDeleteHistory = (index) =>
    {
        apiService.delete(`history/${index}`).then(getHistory);
    };



    const recallHistory = (index) =>
    {
        doInputChange({ currentTarget: { value: history[index].equation}});
    };



    return (
        <div className="bg-dark d-flex flex-column flex-grow-1">
            <CalcResult value={calcResult} isValid={isValid} />
            <CalcInput value={calcValue} handleChange={doInputChange} handleSaveHistory={doSaveHistory} />
            <div className="d-flex mt-3 flex-grow-1 pt-3">
                { Object.keys(variables).length > 0 && <div className="position-relative flex-grow-1 overflow-y">
                    <div className="d-flex flex-column px-3 position-absolute h-100 w-100">
                        <span className="text-light text-center fs-3">Variables</span>
                    {
                        objToArray(variables).map((variable) =>
                        <VariableInput key={variable.key} name={variable.key} value={variable.value} handleChange={doVariableChange} />
                        )
                    }
                    </div> 
                </div> }
                { history.length > 0 && <div className="position-relative flex-grow-1">
                    <div className="d-flex flex-column px-3 overflow-y position-absolute h-100 w-100">
                        <span className="text-light text-center fs-3">History</span>
                        { history.map((entry, index) => <HistoryEntry data={entry} handleDelete={() => { doDeleteHistory(index) }} recallHistory={() => { recallHistory(index) }} key={index} />).reverse() }
                    </div>
                </div> }
            </div>
        </div>
    );
}

export default App;
