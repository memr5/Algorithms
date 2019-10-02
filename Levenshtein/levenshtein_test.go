package main

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestMin(t *testing.T) {
	assert.Equal(t, 1, min(1, 2, 3))
}

func TestLevenshtein(t *testing.T) {
	assert.Equal(t, 1, Levenshtein("", "a"))
	assert.Equal(t, 1, Levenshtein("a", ""))
	assert.Equal(t, 2, Levenshtein("", "ab"))
	assert.Equal(t, 2, Levenshtein("ab", ""))

	assert.Equal(t, 1, Levenshtein("a", "b"))
	assert.Equal(t, 1, Levenshtein("ab", "b"))
	assert.Equal(t, 1, Levenshtein("a", "ab"))
	assert.Equal(t, 3, Levenshtein("kitten", "sitting"))
}
